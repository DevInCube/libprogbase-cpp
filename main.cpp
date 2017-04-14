/**	@file
	@brief sample usage
*/
#include <iostream>
#include <vector>

#include <progbase-cpp/net.h>

using namespace std;

int main(void) {
	progbase::net::IpAddress addr("127.0.0.1", 80);
	cout << addr.address() << endl;
	return 0;
}
