//ScreenRecorder_client.h
/*
 *	Code copyright by wangyunjin 
 *	Date@20120906
 *     The ScreenRecorder_client Interface for interaction
 *	 with ScreenRecorder_server process
 *
 *   ����Ӧ�÷�Ϊ�����֣�1. ������̣�ϵͳ���̣�2. Ӧ�ò��httpserver 3. Ӧ�ò��UI
 *   Ӧ�ò���̺ͱ�����̵�ͨ�Ź����Լ��������Ļ�ȡ��ͨ��һ��localsocket��ɡ�
 *		1> localsocket�ڱ�������д���������ͨѶ�ӿ��������̶Խ�
 *		2> httpserver Ŀǰ��Ϊһ���̴߳�����Ӧ�ý����У�Ҳ��˵������̵���Ӧ�ñ���һֱ���С���δ��Ҫ��һ����̨��������httpserver��
 *		3> ������̵�����ʱ����init������ϵͳ�������� Ӧ������
*/

typedef enum {
    OUTPUT_FORMAT_DEFAULT = 0,
    OUTPUT_FORMAT_THREE_GPP = 1,
    OUTPUT_FORMAT_MPEG_4 = 2,
    /* H.264/AAC data encapsulated in MPEG2/TS */
    OUTPUT_FORMAT_MPEG2TS = 8,

    OUTPUT_FORMAT_LIST_END // must be last - used to validate format type

}output_format_e;

typedef   void (*LISTENFUNC)(void *);

/*���ӱ�����̵�localsocket��EVENT_CONNECT������ʼ������*/
int screenrecorder_init(int *connSockFd,int *cmdSockFd);

/*���ñ���֡�ʣ�ͨ����localsocket���� EVENT_SET_RATE��*/
int screenrecorder_set_rate(int cmdSockFd, int fps);

/*���ñ���֡�ʣ�ͨ����localsocket���� EVENT_SET_OUTPUTFORMAT)*/
int screenrecorder_set_format(int cmdSockFd, output_format_e format);

/*���ñ���֡�ʣ�ͨ����localsocket���� EVENT_SET_OUTPUTSIZE)*/
int screenrecorder_set_size(int cmdSockFd, int width, int height);

/*��ʼ¼����Ļ��Ƶ����EVENT_START��*/
int screenrecorder_start(int cmdSockFd, int connSockFd,  LISTENFUNC func, void *data);

/*����¼����Ļ��Ƶ����EVENT_STOP��*/
int screenrecorder_stop(int cmdSockFd);

/*�Ͽ�localsocket���ӣ�ȥ��ʼ��*/
int screenrecorder_deinit(int connSockFd, int cmdSockFd);
