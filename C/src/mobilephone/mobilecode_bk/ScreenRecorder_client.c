
#include "ScreenRecorder_client.h"

/*���ӱ�����̵�localsocket��EVENT_CONNECT������ʼ������*/
int screenrecorder_init(int *connSockFd,int *cmdSockFd)
{

	return 0;
}

/*���ñ���֡�ʣ�ͨ����localsocket���� EVENT_SET_RATE��*/
int screenrecorder_set_rate(int cmdSockFd, int fps)
{

	return 0;
}

/*���ñ���֡�ʣ�ͨ����localsocket���� EVENT_SET_OUTPUTFORMAT)*/
int screenrecorder_set_format(int cmdSockFd, output_format_e format)
{

	return 0;
}

/*���ñ���֡�ʣ�ͨ����localsocket���� EVENT_SET_OUTPUTSIZE)*/
int screenrecorder_set_size(int cmdSockFd, int width, int height)
{

	return 0;
}

/*��ʼ¼����Ļ��Ƶ����EVENT_START��*/
int screenrecorder_start(int cmdSockFd, int connSockFd,  LISTENFUNC func, void *data)
{

	return 0;
}

/*����¼����Ļ��Ƶ����EVENT_STOP��*/
int screenrecorder_stop(int cmdSockFd)
{

	return 0;
}

/*�Ͽ�localsocket���ӣ�ȥ��ʼ��*/
int screenrecorder_deinit(int connSockFd, int cmdSockFd)
{

	return 0;
}