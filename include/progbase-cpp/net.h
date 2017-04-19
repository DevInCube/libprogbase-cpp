/** @file
    @brief simple C++ wrapper for progbase/net module of libprogbase
*/
#pragma once

#include <iostream>
#include <stdexcept>

namespace pb {
    #include <progbase.h>
    #include <progbase/net.h>

    #ifdef PROGBASE_VERSION
        #if !PROGBASE_VERSION_CHECK(0, 3, 1)
            #error "Please, update your libprogbase to version >= 0.3.1"
        #endif
    #else
        #warning "Update your libprogbase to version >= 0.3.1 to enable version check"
    #endif 
}

namespace progbase {
    namespace net {
        class Ip;
        class IpAddress;
        class NetMessage;
        class NetException;
        class UdpClient;
        class TcpListener;
        class TcpClient;
    }
}

class progbase::net::Ip {
public:
    static std::string resolveHostname(const std::string &hostname);
};

class progbase::net::IpAddress {
    friend class UdpClient;
    friend class TcpClient;
    friend class TcpListener;

    pb::IpAddress _address;
public:
    IpAddress(void);
    IpAddress(const std::string &ipv4, int port);
    std::string address(void);
    int port(void);
};

class progbase::net::NetMessage {
    friend class UdpClient;
    friend class TcpClient;
    friend class TcpListener;

    pb::NetMessage message;
    char * buffer;
    int size;

    void construct(int size);
public:
    NetMessage(int size);
    NetMessage(const NetMessage &other);
    ~NetMessage();

    void setDataString(const std::string & str);
    std::string dataAsString(void);
    bool isEmpty(void);
};

class progbase::net::UdpClient
{
    pb::UdpClient client;
public:
    UdpClient(void);
    ~UdpClient(void);

    void bind(const IpAddress & address);
    void sendTo(NetMessage & message, const IpAddress & address);
    void receiveFrom(NetMessage & message, IpAddress & address);
};

// TCP

class progbase::net::TcpListener {
    pb::TcpListener listener;
public:
    TcpListener(void);
    ~TcpListener(void);

    void bind(const IpAddress &address);
    void start(void);
    TcpClient * accept(void);
};

class progbase::net::TcpClient
{
    friend class TcpListener;

    pb::TcpClient client;
public:
    TcpClient(void);
    ~TcpClient(void);

    void connect(const IpAddress &address);
    void send(NetMessage & message);
    void receive(NetMessage & message);
};

// Exception

class progbase::net::NetException : public std::runtime_error {
public:
    NetException(const std::string &msg);
    std::string message(void) __attribute__ ((deprecated));
    std::string message(void) const __attribute__ ((deprecated));
};
