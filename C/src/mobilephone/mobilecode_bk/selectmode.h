
#ifndef _SELECT_MODE_H_
#define _SELECT_MODE_H_ 

enum
{
    CLIENT_CONNECT_IDLE,
    CLIENT_CONNECT_BUSY
};

typedef struct
{
	int connFd;
	int cmdFd;
}PTHREAD_PARA_S;

typedef struct
{
    int connect_count;
    int listen_fd;
    fd_set read_fds;
    struct sockaddr_in servaddr;
}TCP_SERVER;

typedef struct
{
    int index;
    int state;
    int accept_fd;

}TCP_CLIENT;

typedef struct
{
    int g_exit_flag;
    TCP_SERVER tcp_server;
    TCP_CLIENT tcp_client[10];  
}MOBILEPHONE_VAR;

int localsocketfd;
int connsocketfd;
PTHREAD_PARA_S *para;
pthread_mutex_t p_lock=PTHREAD_MUTEX_INITIALIZER;

/*��ʼ����װ*/
int init_localsocket();
int init_size(int height,int width);
int init_rate(int rate);
int init_format(int format);

/*��ʼ¼��*/
int start_record();

/*д���ر���*/
int localwrite(char * pathname);

/*���͵�����*/
int httpserver(int port);

/*ֹͣ¼��*/
int stop_record();

/*ȥ��ʼ����װ*/
int deinit_localsocket();

#endif  //_SELECT_MODE_H_
