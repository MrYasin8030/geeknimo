<?php
		
		//��ȷ����100
		//���󷵻�
		//	101���ʺŻ����������
		//
		//	120��û�л���ʺź�����
		
		
		if(isset($_GET['username'])  && isset($_GET['password'])){
				
				if($_GET['username'] == "admin" && $_GET['password'] == "123456"){
						echo "100";
				}else {
				 		echo "101";
				}
			
		}else {
		 		echo "120";
		}

?>