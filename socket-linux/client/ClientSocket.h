// Definition of the ClientSocket class

#ifndef ClientSocket_class
#define ClientSocket_class

#include "socket_base/Socket.h"
#include "socket_base/SocketException.h"



class ClientSocket : public Socket
{
 public:

    ClientSocket ( std::string host, int port );
    virtual ~ClientSocket();

    const ClientSocket& operator << ( const std::string& ) const;
    const ClientSocket& operator >> ( std::string& ) const;
    
    const ClientSocket& operator << ( void* ) const;
    const ClientSocket& operator >> ( void* ) const;
private:
	int send_packet_index;

};


#endif
