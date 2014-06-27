.PUBLIC _FIQ
//...............................................
.EXTERNAL _BSR_FIQ_Routine
.EXTERNAL __gIsStopRecog //����ֵ = 0 ��ʶ��æ
						 //       = 1 ��ʶ��ֹͣ
						 

.PUBLIC _BREAK,_IRQ0, _IRQ1, _IRQ2, _IRQ3, _IRQ4, _IRQ5, _IRQ6, _IRQ7
.EXTERNAL _PlayFlag
//..................................................
.INCLUDE s480.inc;
.INCLUDE A2000.inc;
.INCLUDE resource.inc
.INCLUDE hardware.inc

.TEXT
_FIQ:
	push R1,R4 to [SP]
	R1 = [P_INT_Ctrl]
	R1 &= 0x2000
	jz ?notTimerA						//����ΪTIQ_TMA����ת
	R1 = [__gIsStopRecog]
	jnz ?BSR_NotBusy					//[__gIsStopRecog]Ϊ1��ת����������
	call _BSR_FIQ_Routine				//Ϊ0�����ñ�ʶ�ӳ���
	jmp ?BSR_Busy						//�����ж�
?BSR_NotBusy:							//��������
	R2 = [_PlayFlag]
	jnz ?Play2000						//[_PlayFlag]Ϊ1���ǲ���2000
	call F_FIQ_Service_SACM_S480;		//Ϊ0������480
	jmp ?BSR_Busy						//�����ж�
?Play2000:								//2000�����ӳ���
	call F_FIQ_Service_SACM_A2000;
?BSR_Busy:								//�����ж�
	R1 = 0x2000
	[P_INT_Clear] = R1
	pop	R1,R4 from [SP];
	reti;
?notTimerA:
	R1 = 0x8800;
    [P_INT_Clear] = R1;
	pop	R1,R4 from [SP];
	reti;

_BREAK: 
_IRQ0:
_IRQ1: 
_IRQ2: 
_IRQ3: 
_IRQ4: 
_IRQ5: 
_IRQ6: 
_IRQ7:
.END