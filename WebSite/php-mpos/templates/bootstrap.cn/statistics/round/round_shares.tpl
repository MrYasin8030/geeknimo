  <div class="col-lg-6">
    <div class="panel panel-info">
      <div class="panel-heading">
        <i class="fa fa-refresh fa-fw"></i> 本轮股份
      </div>
      <div class="panel-body">
        <div class="table-responsive">
          <table class="table table-striped table-bordered table-hover {if $ROUNDSHARES}datatable{/if}">
            <thead>
              <tr>
                <th>名次</th>
                <th>用户名</th>
                <th>有效的</th>
                <th>无效的</th>
                <th>无效 %</th>
              </tr>
            </thead>
            <tbody>
{assign var=rank value=1}
{assign var=listed value=0}
{foreach key=id item=data from=$ROUNDSHARES}
              <tr{if $GLOBAL.userdata.username|default:"" == $data.username}{assign var=listed value=1} style="background-color:#99EB99;"{else}{/if}>
                <td>{$rank++}</td>
                <td>{if $data.is_anonymous|default:"0" == 1 && $GLOBAL.userdata.is_admin|default:"0" == 0}anonymous{else}{$data.username|default:"unknown"|escape}{/if}</td>
                <td>{$data.valid|number_format}</td>
                <td>{$data.invalid|number_format}</td>
                <td>{if $data.invalid > 0 }{($data.invalid / $data.valid * 100)|number_format:"2"|default:"0"}{else}0.00{/if}</td>
              </tr>
{/foreach}
            </tbody>
          </table>
        </div>
      </div>
    </div>
  </div>
