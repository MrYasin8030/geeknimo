 <div class="row">
    <div class="col-lg-12">
      <div class="panel panel-info">
        <div class="panel-heading">
          <i class="fa fa-question fa-fw"></i> �ڿ�ָ��
        </div>
        <div class="panel-body">
        
    <p>1. <strong>�����˺�.</strong></p>
      <ul>
        <li>���� <a href="{$smarty.server.SCRIPT_NAME}?page=register">ע���˺�</a>, ��������ʺ���<a href="{$smarty.server.SCRIPT_NAME}?page=login">��½</a></li>
        <li>���һ������ <a href="{$smarty.server.SCRIPT_NAME}?page=account&action=workers">��</a> �����ڿ����ĵ�½</li>
      </ul>
    </li>
    <p>2. <strong>���زɿ����</strong></p>
      <ul>
        <li><em>Intel/ATI/AMD CGMiner Windows Sha256:</em> <a href="http://ck.kolivas.org/apps/cgminer/cgminer-4.2.2-windows.zip" target="_blank"> �������</a></li>
        <li><em>Intel/ATI/AMD CGMiner Linux Sha256:</em> <a href="http://ck.kolivas.org/apps/cgminer/cgminer-4.2.2.tar.bz2" target="_blank"> �������</a></li>
	<li><em>Intel/ATI/AMD CGMiner 3.7.2 Scrypt Windows:</em> <a href="https://mega.co.nz/#!iQhlGIxa!mzKOfLY6TpOfvPvWE6JFlWdRgHEoshzm99f1hd3ZdRw" target="_blank"> �������</a></li>	
	<li><em>Intel/ATI/AMD CGMiner 3.7.2 Scrypt Linux:</em> <a href="http://ck.kolivas.org/apps/cgminer/3.7/cgminer-3.7.0.tar.bz2" target="_blank"> �������</a></li>	
	<li><em>Intel/ATI/AMD BFGMiner Linux/Windows:</em> <a href="http://bfgminer.org" target="_blank"> �������</a></li>
        <li><em>Fabulous Panda Miner Mac OS X:</em> <a href="http://fabulouspanda.co.uk/macminer/" target="_blank"> �������</a></li>
        <li><em>Minerd CPU Miner Mac/Linux/Windows:</em><a href="https://bitcointalk.org/index.php?topic=55038.msg654850#msg654850" target="_blank"> �������</a>.</li>
        <li><em>NVIDIA Cudaminer:</em><a href="https://mega.co.nz/#!ZQxxRKJI!W_H00CQCBdQZUpgokQWmAsteplcbQfc-j44LrAvM9oQ" target="_blank"> �������</a></li>
	  </ul>
    </li>
    <p>3. <strong>���òɿ����</strong></p>
    <ul>
      <p>�����ʹ��Linuxϵͳ,���������µ�����̨:</p>
      <li>CGMiner</li>
      <pre>./cgminer {if $GLOBAL.config.algorithm == 'scrypt'}--scrypt{/if} -o stratum+tcp://{$SITESTRATUMURL|default:$smarty.server.SERVER_NAME}:{$SITESTRATUMPORT|default:"3333"} -u <em>Weblogin</em>.<em>WorkerName</em> -p <em>WorkerPassword</em></pre>
      <li>BFGMiner</li>
      <pre>./bfgminer {if $GLOBAL.config.algorithm == 'scrypt'}--scrypt{/if} -o stratum+tcp://{$SITESTRATUMURL|default:$smarty.server.SERVER_NAME}:{$SITESTRATUMPORT|default:"3333"} -u <em>Weblogin</em>.<em>WorkerName</em> -p <em>WorkerPassword</em></pre>
      <br />
	  <p> ��������� <strong> Windows Operating System </strong>����ϵͳ���ھ�, ��ô�����Ҫ����һ���������ļ�����������ڿ����. </p><p> ������� <a href="https://mega.co.nz/#F!zdB3iDgS!MQfawuzu0FoEQ6sDEJSLnQ" target="_blank">����</a> ����Ԥ���õ�һ��������������Լ��򿪼��±���Ȼ���ƺ�ճ��</p>
	  <li>MinerD</li>
      <pre>minerd -a {if $GLOBAL.config.algorithm == 'scrypt'}--scrypt{/if} -t 6 -s 4 -o stratum+tcp://{$SITESTRATUMURL|default:$smarty.server.SERVER_NAME}:{$SITESTRATUMPORT|default:"3333"} -u <em>Weblogin</em>.<em>WorkerName</em> -p <em>WorkerPassword</em></pre>
      <li>CGMiner</li>
      <pre>cgminer {if $GLOBAL.config.algorithm == 'scrypt'}--scrypt{/if} -o stratum+tcp://{$SITESTRATUMURL|default:$smarty.server.SERVER_NAME}:{$SITESTRATUMPORT|default:"3333"} -u <em>Weblogin</em>.<em>WorkerName</em> -p <em>WorkerPassword</em></pre>
      <li>BFGMiner</li>
      <pre>bfgminer {if $GLOBAL.config.algorithm == 'scrypt'}--scrypt{/if} -o stratum+tcp://{$SITESTRATUMURL|default:$smarty.server.SERVER_NAME}:{$SITESTRATUMPORT|default:"3333"} -u <em>Weblogin</em>.<em>WorkerName</em> -p <em>WorkerPassword</em></pre>
      <li>Cudaminer For NVIDIA Cards</li>
	  <pre>cudaminer -o stratum+tcp://{$SITESTRATUMURL|default:$smarty.server.SERVER_NAME}:{$SITESTRATUMPORT|default:"3333"} -u <em>Weblogin</em>.<em>WorkerName</em> -p <em>WorkerPassword</em></pre>
	  <br />
	  <p> Ȼ������Ҫ���ġ�-u Weblogin.Worker -p Worker password" Ϊ���Լ��Ŀ󹤺� �� ������, ���磺"-u username.001 -p 123456" Ȼ����� "�ļ� => ���Ϊ" ���ļ�����Ϊ "RunMe.bat" ��Ҫ����������ڿ����ͬ��Ŀ¼��. �����ڿ��Կ��ɣ�˫����RunMe.bat����ʼ�ھ��������Ҫ��������Ŀ�������ѡ����û���������, ����<a href="{$smarty.server.SCRIPT_NAME}?page=account&action=workers">���</a></p>
    </ul>
    <p>4. <strong>�������� {$SITECOINNAME|default:"Litecoin"} �տ�Ǯ����ַ.</strong></p>
      <ul>
        <li> ����Ǯ���ͻ���: ���� {$SITECOINNAME|default:"Litecoin"} �ͻ��� <a href="{$SITECOINURL|default:"http://www.litecoin.org"}" target="_blank">�������</a>.
          <p>����һ���µ�Ǯ����ַ�����µ��տ��ַ����������ʻ�ҳ���տ��ַ��.</p>
        </li>
      </ul>
    </li>
    <p>5. <strong>�߼� cgminer ���� / ��������</strong></p>
      <ul>
        <li><a href="https://raw.github.com/ckolivas/cgminer/v3.7.2/SCRYPT-README" target="_blank">Scrypt readme</a></li>
        <li>Don't set <b>intensity</b> too high, I=11 is standard and safest. Higher intensity takes more GPU RAM. Check for <b>hardware errors</b> in cgminer (HW). HW=0 is good, otherwise lower intensity :)</li>
        <li>Set shaders according to the readme (or look at your graphic cards specifications). Cgminer uses this value at first run to calculate <b>thread-concurrency</b>. Easiest way to get this optimized is to use same settings as others have used here: <a href="http://litecoin.info/Mining_Hardware_Comparison" target="_blank">here</a>.</li>
        <li>There's also an interesting project which gives you a GUI for cgminer. Windows only it seems.</li>
        <li>Here's a great <a href="https://docs.google.com/document/d/1Gw7YPYgMgNNU42skibULbJJUx_suP_CpjSEdSi8_z9U/preview?sle=true" target="_blank">guide</a> how to get up and running with Xubuntu.</li>
      </ul>
    </li>
        </div>
      </div>
    </div>
    <!-- /.col-lg-12 -->
  </div>
