<form action="{$smarty.server.SCRIPT_NAME}" method="post" role="form">
  <input type="hidden" name="page" value="{$smarty.request.page|escape}">
  <input type="hidden" name="action" value="{$smarty.request.action|escape}">
  <input type="hidden" name="do" value="updateAccount">
  <input type="hidden" name="ctoken" value="{$CTOKEN|escape|default:""}" />
  <div class="col-lg-6">
    <div class="panel panel-info">
      <div class="panel-heading">
        <i class="fa fa-edit fa-fw"></i> 账户详细信息
      </div>
      <div class="panel-body">
        <div class="row">
          <div class="col-lg-12">
            <div class="form-group">
              <label>用户名</label>
              <input class="form-control" type="text" value="{$GLOBAL.userdata.username|escape}" disabled />
            </div>
            <div class="form-group">
              <label>用户ID</label>
              <input class="form-control" type="text" value="{$GLOBAL.userdata.id}" disabled />
            </div>
            {if !$GLOBAL.website.api.disabled}
            <div class="form-group">
              <label>API Key</label>
              <br>
              <a href="{$smarty.server.SCRIPT_NAME}?page=api&action=getuserstatus&api_key={$GLOBAL.userdata.api_key}&id={$GLOBAL.userdata.id}">{$GLOBAL.userdata.api_key}</a>
            </div>
            {/if}
            <div class="form-group">
              <label>邮箱地址</label>
              {nocache}<input class="form-control" type="text" name="email" value="{$GLOBAL.userdata.email|escape}" size="20" {if $GLOBAL.twofactor.enabled && $GLOBAL.twofactor.options.details && !$DETAILSUNLOCKED}id="disabledInput" disabled{/if}/>{/nocache}
            </div>
            <div class="form-group">
              <label>钱包地址</label>
              {nocache}<input class="form-control" type="text" name="paymentAddress" value="{$smarty.request.paymentAddress|default:$GLOBAL.userdata.coin_address|escape}" size="40"  {if $GLOBAL.twofactor.enabled && $GLOBAL.twofactor.options.details && !$DETAILSUNLOCKED}id="disabledInput" disabled{/if}/>{/nocache}
            </div>
            <div class="form-group">
              <label>时区选择</label>
              {nocache}
              <select class="form-control" name="timezone">
                {html_options options=$TIMEZONES selected=$GLOBAL.userdata.timezone}
              </select>
              {/nocache}
            </div>
            <div class="form-group">
              <label>捐赠百分比</label>
              <font size="1"> 捐赠金额的百分比 (例如：{$DONATE_THRESHOLD.min} - 100%)</font>
              {nocache}<input class="form-control" type="text" name="donatePercent" value="{$smarty.request.donatePercent|default:$GLOBAL.userdata.donate_percent|escape|number_format:"2"}" size="4" {if $GLOBAL.twofactor.enabled && $GLOBAL.twofactor.options.details && !$DETAILSUNLOCKED}id="disabledInput" disabled{/if}/>{/nocache}
            </div>
            <div class="form-group">
              <label>自动付款设置</label>
              </br>
              <font size="1">{$GLOBAL.config.ap_threshold.min} - {$GLOBAL.config.ap_threshold.max} {$GLOBAL.config.currency}. 设置 '0' 则不自动提币. 自动提币收取 {if $GLOBAL.config.txfee_auto > 0.00001}{$GLOBAL.config.txfee_auto}{else}{$GLOBAL.config.txfee_auto|number_format:"8"}{/if} {$GLOBAL.config.currency} TX网络费 <span id="tt"><img width="15px" height="15px" title="This {if $GLOBAL.config.txfee_auto > 0.00001}{$GLOBAL.config.txfee_auto}{else}{$GLOBAL.config.txfee_auto|number_format:"8"}{/if} 自动支付收取的费用是TX网络交易费,不是矿池收取." src="site_assets/mpos/images/questionmark.png"></span></font>
              </br>
              <input class="form-control" type="text" name="payoutThreshold" value="{nocache}{$smarty.request.payoutThreshold|default:$GLOBAL.userdata.ap_threshold|escape}{/nocache}" size="{$GLOBAL.config.ap_threshold.max|strlen}" maxlength="{$GLOBAL.config.ap_threshold.max|strlen}" {if $GLOBAL.twofactor.enabled && $GLOBAL.twofactor.options.details && !$DETAILSUNLOCKED}id="disabledInput" disabled{/if}/>
            </div>
            <div class="form-group">
              <label>匿名帐户</label>
              <input type="hidden" name="is_anonymous" value="0" />
              <input type="checkbox" class="switch" data-size="mini"  name="is_anonymous" id="is_anonymous" value="1" {if $GLOBAL.userdata.is_anonymous}checked{/if} {if $GLOBAL.twofactor.enabled && $GLOBAL.twofactor.options.details && !$DETAILSUNLOCKED}id="disabledInput" disabled{/if}/>
              </br>
              <font size="1">隐藏您的用户名，这样其他普通用户看不到你的真实用户名. (管理员还是可以看到的).</font>
            </div>
            <div class="form-group">
              <label>4 数字取币PIN码</label>
              <font size="1">您在注册时填写的4位数PIN</font>
              <input class="form-control" type="password" name="authPin" size="4" maxlength="4">
            </div>
            
          </div>
        </div>
      </div>
      <div class="panel-footer">
      {nocache}
      <input type="hidden" name="ctoken" value="{$CTOKEN|escape|default:""}" />
      <input type="hidden" name="ea_token" value="{$smarty.request.ea_token|escape|default:""}">
      <input type="hidden" name="utype" value="account_edit">
      {if $GLOBAL.twofactor.enabled && $GLOBAL.twofactor.options.details}
      {if $DETAILSSENT == 1 && $DETAILSUNLOCKED == 1}
      <input type="submit" value="Update Account" class="btn btn-success btn-sm">
      {elseif $DETAILSSENT == 0 && $DETAILSUNLOCKED == 1 || $DETAILSSENT == 1 && $DETAILSUNLOCKED == 0}
      <input type="submit" value="Update Account" class="btn btn-danger btn-sm" disabled>
      {elseif $DETAILSSENT == 0 && $DETAILSUNLOCKED == 0}
      <input type="submit" value="Unlock" class="btn btn-warning btn-sm" name="unlock">
      {/if}
      {else}
      <input type="submit" value="更新账户信息" class="btn btn-success btn-sm">
      {/if}
      {/nocache}
      </div>
    </div>
  </div>
</form>
