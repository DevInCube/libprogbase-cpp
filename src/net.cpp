#include <cstring>

#include <progbase-cpp/net.h>

using namespace progbase::net;

// IP

std::string Ip::resolveHostname(const std::string &hostname) {
    char ipv4[20] = "";
    if (!pb::Ip_resolveHostname(ipv4, hostname.c_str())) {
        throw NetException("Resolve hostname error");
    }
    return ipv4;
}

IpAddress::IpAddress(void) {
    pb::IpAddress_initAny(&_address, 0);
}

IpAddress::IpAddress(const std::string &ipv4, int port) {
    pb::IpAddress_init(&_address, ipv4.c_str(), port);
}

std::string IpAddress::address(void) {
    return pb::IpAddress_address(&_address);
}

int IpAddress::port(void) {
    return pb::IpAddress_port(&_address);
}

// NetMessage

void NetMessage::construct(int size) {
    buffer = new char[size];
    this->size = size;
    pb::NetMessage_init(&message, buffer, size);
}

NetMessage::NetMessage(int size) {
    construct(size);
}

NetMessage::NetMessage(const NetMessage &other) {
    construct(other.size);
    memcpy(buffer, other.buffer, sizeof(char) * size);
}

NetMessage::~NetMessage(void) {
    delete [] buffer;
}

void NetMessage::setDataString(const std::string & str) {
    if (str.length() >= message.bufferLength) {
        throw std::overflow_error("input string is longer than message buffer");
    }
    pb::NetMessage_setDataString(&message, str.c_str());
}

std::string NetMessage::dataAsString(void) {
    return buffer;
}

bool NetMessage::isEmpty(void) {
    return message.dataLength == 0;
}

// UDP

UdpClient::UdpClient(void) {
    pb::UdpClient_init(&client);
}

UdpClient::~UdpClient(void) {
    pb::UdpClient_close(&client);
}

void UdpClient::bind(const IpAddress &address) {
    if (!pb::UdpClient_bind(&client, (pb::IpAddress *)(&address._address))) {
        throw NetException("Can't bind to address");
    }
}

void UdpClient::receiveFrom(NetMessage &message, IpAddress &address) {
    if(!pb::UdpClient_receiveFrom(&client, &message.message, &address._address)) {
        throw NetException("Error at receive");
    }
}

void UdpClient::sendTo(NetMessage &message, const IpAddress &address) {
    if(!pb::UdpClient_sendTo(&client, &message.message, (pb::IpAddress *)&address._address)){
        throw NetException("Error at send");
    }
}

// Exception

NetException::NetException(const std::string &msg) 
    : std::runtime_error(msg) {
    //
}

std::string NetException::message(void) {
    return what();
}

std::string NetException::message(void) const {
    return what();
}

// TCP

TcpListener::TcpListener(void) {
    pb::TcpListener_init(&listener);
}

TcpListener::~TcpListener(void) {
    pb::TcpListener_close(&listener);
}

void TcpListener::bind(const IpAddress &address) {
    if (!pb::TcpListener_bind(&listener, (pb::IpAddress *)(&address._address))) {
        throw NetException("Can't bind to address");
    }
}

void TcpListener::start(void) {
    if (!pb::TcpListener_start(&listener)) {
        throw NetException("Can't start listener");
    }
}

TcpClient * TcpListener::accept(void) {
    TcpClient * client = new TcpClient;
    pb::TcpListener_accept(&listener, &client->client);
    return client;
}

TcpClient::TcpClient(void) {
    pb::TcpClient_init(&client);
}

TcpClient::~TcpClient(void) {
    pb::TcpClient_close(&client);
}

void TcpClient::connect(const IpAddress &address) {
    if (!pb::TcpClient_connect(&client, (pb::IpAddress *)&address._address)){
        throw NetException("Error at connect");
    }
}

void TcpClient::connect(const IpAddress &address, const Ssl &ssl) {
    if (!pb::TcpClient_connectSecure(
            &client, 
            (pb::IpAddress *)&address._address,
            (pb::Ssl *)&ssl.ssl)) {
        throw NetException("Error at connect");
    }
}

void TcpClient::receive(NetMessage &message) {
    if(!pb::TcpClient_receive(&client, &message.message)){
        throw NetException("Error at send");
    }
}

void TcpClient::send(NetMessage &message) {
    if(!pb::TcpClient_send(&client, &message.message)){
        throw NetException("Error at send");
    }
}

Ssl::Ssl(void) {
    pb::Ssl_init(&ssl);
}

Ssl::~Ssl(void) {
    pb::Ssl_cleanup(&ssl);
}
