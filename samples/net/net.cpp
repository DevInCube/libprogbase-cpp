#include <iostream>
#include <progbase-cpp/net.h>

using namespace std;
using namespace progbase::net;

int udpClient() {
    UdpClient client;
    NetMessage message(100);
    IpAddress serverAddress("127.0.0.1", 9999);
    try {
        message.setDataString("Hello, UDP!");
        client.sendTo(message, serverAddress);
        cout << ">> Request sent" << endl;
        client.receiveFrom(message, serverAddress);
        std::string str = message.dataAsString();
        cout << ">> Received " << str.length() << " bytes: " << endl << str << endl;
    } catch (const NetException & exc) {
        cerr << exc.what() << endl;
    }
    return 0;
}

int udpServer() {
    const int serverPort = 9999;
    UdpClient server;
    NetMessage message(100);
    IpAddress clientAddress;

    try {
        server.bind(IpAddress("127.0.0.1", serverPort));
        while (true) {
            cout << ">> Waiting for data at " << serverPort << "..." << endl;
            server.receiveFrom(message, clientAddress);
            cout << ">> Received: " << endl << message.dataAsString() << endl;
            server.sendTo(message, clientAddress);
            cout << ">> Response sent." << endl;
        }
    } catch (const NetException & exc) {
        cerr << exc.what() << endl;
    }
    return 0;
}

int tcpServer() {
    const int serverPort = 3000;
    TcpListener listener;
    NetMessage message(100);
    try {
        listener.bind(IpAddress("127.0.0.1", serverPort));
        listener.start();
        while (true) {
            cout << ">> Waiting for clients at " << serverPort << "..." << endl;
            TcpClient * client = listener.accept();
            client->receive(message);
            cout << ">> Received: " << endl << message.dataAsString() << endl;
            client->send(message);
            cout << ">> Response sent." << endl;
            delete client;
        }
    } catch (const NetException & exc) {
        cerr << exc.what() << endl;
    }
    return 0;
}

int tcpWebClient(void) {
    TcpClient client;
    NetMessage message(100);
    try {
        client.connect(IpAddress(Ip::resolveHostname("progbase.herokuapp.com"), 80));
        message.setDataString("GET / HTTP/1.0\r\nHost: progbase.herokuapp.com\r\n\r\n");
        client.send(message);
        cout << ">> Request sent" << endl;
        do {
            client.receive(message);
            std::string str = message.dataAsString();
            cout << ">> Received " << str.length() << " bytes: " << endl << str << endl;
        } while (!message.isEmpty());
    } catch (const NetException & exc) {
        cerr << exc.what() << endl;
    }
    return 0;
}

int main(void)
{ 
    return udpClient();
}
