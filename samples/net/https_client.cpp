#include <iostream>
#include <progbase-cpp/net.h>

using namespace std;
using namespace progbase::net;

int httpsClient(void) {
    TcpClient client;
    NetMessage message(100);
    try {
		auto ipAddress = IpAddress(Ip::resolveHostname("api.sunrise-sunset.org"), 443);
		Ssl ssl;
        client.connect(ipAddress, ssl);
        message.setDataString(
			"GET /json?lat=36.7201600&lng=-4.4203400 HTTP/1.0\r\n"
			"Host: api.sunrise-sunset.org\r\n"
			"\r\n");
        client.send(message);
        cout << ">> Request sent" << endl;
        do {
            client.receive(message);
            std::string str = message.dataAsString();
            cout << ">> Received " << str.length() << " bytes: " << endl << str << endl;
        } while (!message.isEmpty());
    } catch(NetException const & exc) {
        cerr << exc.what() << endl;
    }
    return 0;
}

int main(void)
{ 
    return httpsClient();
}
