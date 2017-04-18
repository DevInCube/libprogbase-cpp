/**	@file
	@brief sample usage
*/
#include <iostream>
#include <vector>

#include <progbase-cpp/net.h>

using namespace std;

int main(void) {
	try {
		throw progbase::net::NetException("Error");
		progbase::net::IpAddress addr("127.0.0.1", 80);
		cout << addr.address() << endl;
	} catch (progbase::net::NetException const & exc) {
		cerr << exc.what() << endl;
	}
	return 0;
}
