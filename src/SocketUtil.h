#ifndef SOCKET_UTIL_H
#define SOCKET_UTIL_H

enum SocketAddressFamily
{
	INET = AF_INET,
	INET6 = AF_INET6
};

class SocketUtil
{
public:

	static bool StaticInit();
	static void CleanUp();

	static void ReportError(const char* inOperationDesc);
	static int  GetLastError();

	static int  Select(
			const std::vector< TCPSocketPtr >* inReadSet,
			std::vector< TCPSocketPtr >* outReadSet,
			const std::vector< TCPSocketPtr >* inWriteSet,
			std::vector< TCPSocketPtr >* outWriteSet,
			const std::vector< TCPSocketPtr >* inExceptSet,
			std::vector< TCPSocketPtr >* outExceptSet);

	static UDPSocketPtr	CreateUDPSocket(SocketAddressFamily inFamily);
	static TCPSocketPtr	CreateTCPSocket(SocketAddressFamily inFamily);

private:

	static fd_set* FillSetFromVector(fd_set& outSet, const std::vector< TCPSocketPtr >* inSockets, int& ioNaxNfds);
	static void FillVectorFromSet(std::vector< TCPSocketPtr >* outSockets, const std::vector< TCPSocketPtr >* inSockets, const fd_set& inSet);
};

#endif // SOCKET_UTIL_H
