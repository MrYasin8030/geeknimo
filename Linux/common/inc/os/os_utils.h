#ifndef _OS_UTILS_H_
#define _OS_UTILS_H_


#ifdef __cplusplus
extern "C" {
#endif

/*
��XML�ַ����л�ȡһ����ǩ�ڵ��ַ�����Ʃ��:

in_xmlָ��ָ��:
<a>
	<b>xxx</b>
</a>

�������get_xml_node_str(xmlbuf,"a",outbuf,20); ��󷵻ص���<b>xxx</b>
�������get_xml_node_str(xmlbuf,"b",outbuf,20); ��󷵻ص���xxx

����˵��:
in_xml  -- ����xmlָ�룬ע�������xml�м�һ�Σ���һ��Ҫ������xml
node    -- xml node���ƣ����ܳ���56�ֽڣ�������ǰ���<>������Ҫ��ǰ��<>֮�䲻���пո�
out_buf -- ���buf
len       -- ���buf����
p_tail   -- �����ɷ���ʱָ��λ�á�����������һ�εĲ���

������ȱ��˵��:
����������ʺϼ򵥶���Ч�ʸߡ��ʺϷ���һ��������ڲ�xmlͨ�ŵ�
�����ͽ���

ע��:   node name�ĳ�����಻�ó���56�ֽ�
*/
int os_get_xml_node_value(char * in_xml,char *node,char *out_buf,int len, char ** p_tail);


//��ȡ����ָ�뿪ʼ�ĵ�һ���ڵ�����������ָ��ָ����β
// ע��: �����ȡ��xml���治����ע�ͣ���ע�͵Ļ����ܻ����
int os_get_xml_node_name(char * in_xml,char *node_name,int len, char ** p_tail);

#ifdef __cplusplus
}
#endif

#endif


