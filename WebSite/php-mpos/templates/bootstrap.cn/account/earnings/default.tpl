{if $DISABLE_TRANSACTIONSUMMARY|default:"0" != 1}
<div class="row">
  <div class="col-lg-12">
    <div class="panel panel-info">
      <div class="panel-heading">
        <i class="fa fa-money fa-fw"></i> 总 {$GLOBAL.config.currency} 收益记录
      </div>
      <div class="panel-body">
        <div class="row">
          <div class="col-lg-12">
            <div class="panel panel-info">
              <div class="panel-heading">
                <i class="fa fa-credit-card fa-fw"></i> 总计
              </div>
              <div class="panel-body">
                <table class="table table-striped table-bordered table-hover">
                  <thead>
                    <tr>
                      <th class="col-xs-1"></th>
                      {foreach $SUMMARY as $type=>$total}
                      <th>{$type}</th>
                      {/foreach}
                    </tr>
                  </thead>
                  <tbody>
                    <tr>
                      <td class="col-xs-1">所有时间</td>
                      {foreach $SUMMARY as $type=>$total}
                      <td class="right">{$total|number_format:"8"}</td>
                      {/foreach}
                    </tr>
                  </tbody>
                </table>
              </div>
            </div>
          </div>
        </div>

        <div class="row">
          <div class="col-lg-12">
            <div class="panel panel-info">
              <div class="panel-heading">
                <i class="fa fa-clock-o fa-fw"></i> 按时间排序
              </div>
              <div class="panel-body">
                <table class="table table-striped table-bordered table-hover">
                  <thead>
                    <tr>
                      <th class="col-xs-1"></th>
                      <th>Credit</th>
                      <th>Bonus</th>
                      <th>自动支付</th>
                      <th>手动支付</th>
                      <th>捐赠</th>
                      {if $GLOBAL.fees > 0}
                      <th>矿池手续费</th>
                      {/if}
                      <th>TX网络费用</th>
                    </tr>
                  </thead>
                  <tbody>
                    <tr>
                      <td class="col-xs-1">最近一小时</th>
                      <td>{$BYTIME.1HourCredit|number_format:"8"}</td>
                      <td>{$BYTIME.1HourBonus|number_format:"8"}</td>
                      <td>{$BYTIME.1HourDebitAP|number_format:"8"}</td>
                      <td>{$BYTIME.1HourDebitMP|number_format:"8"}</td>
                      <td>{$BYTIME.1HourDonation|number_format:"8"}</td>
                      {if $GLOBAL.fees|default:"0" > 0}
                      <td>{$BYTIME.1HourFee|number_format:"8"}</td>
                      {/if}
                      <td>{$BYTIME.1HourTXFee|number_format:"8"}</td>
                    </tr>
                    <tr>
                      <td class="col-xs-1">最近一天</th>
                      <td>{$BYTIME.24HourCredit|number_format:"8"}</td>
                      <td>{$BYTIME.24HourBonus|number_format:"8"}</td>
                      <td>{$BYTIME.24HourDebitAP|number_format:"8"}</td>
                      <td>{$BYTIME.24HourDebitMP|number_format:"8"}</td>
                      <td>{$BYTIME.24HourDonation|number_format:"8"}</td>
                      {if $GLOBAL.fees|default:"0" > 0}
                      <td>{$BYTIME.24HourFee|number_format:"8"}</td>
                      {/if}
                      <td>{$BYTIME.24HourTXFee|number_format:"8"}</td>
                    </tr>
                    <tr>
                      <td class="col-xs-1">最近一周</th>
                      <td>{$BYTIME.1WeekCredit|number_format:"8"}</td>
                      <td>{$BYTIME.1WeekBonus|number_format:"8"}</td>
                      <td>{$BYTIME.1WeekDebitAP|number_format:"8"}</td>
                      <td>{$BYTIME.1WeekDebitMP|number_format:"8"}</td>
                      <td>{$BYTIME.1WeekDonation|number_format:"8"}</td>
                      {if $GLOBAL.fees|default:"0" > 0}
                      <td>{$BYTIME.1WeekFee|number_format:"8"}</td>
                      {/if}
                      <td>{$BYTIME.1WeekTXFee|number_format:"8"}</td>
                    </tr>
                    <tr>
                      <td class="col-xs-1">最近一月</th>
                      <td>{$BYTIME.1MonthCredit|number_format:"8"}</td>
                      <td>{$BYTIME.1MonthBonus|number_format:"8"}</td>
                      <td>{$BYTIME.1MonthDebitAP|number_format:"8"}</td>
                      <td>{$BYTIME.1MonthDebitMP|number_format:"8"}</td>
                      <td>{$BYTIME.1MonthDonation|number_format:"8"}</td>
                      {if $GLOBAL.fees|default:"0" > 0}
                      <td>{$BYTIME.1MonthFee|number_format:"8"}</td>
                      {/if}
                      <td>{$BYTIME.1MonthTXFee|number_format:"8"}</td>
                    </tr>
                    <tr>
                      <td class="col-xs-1">最近一年</th>
                      <td>{$BYTIME.1YearCredit|number_format:"8"}</td>
                      <td>{$BYTIME.1YearBonus|number_format:"8"}</td>
                      <td>{$BYTIME.1YearDebitAP|number_format:"8"}</td>
                      <td>{$BYTIME.1YearDebitMP|number_format:"8"}</td>
                      <td>{$BYTIME.1YearDonation|number_format:"8"}</td>
                      {if $GLOBAL.fees|default:"0" > 0}
                      <td>{$BYTIME.1YearFee|number_format:"8"}</td>
                      {/if}
                      <td>{$BYTIME.1YearTXFee|number_format:"8"}</td>
                    </tr>
                  </tbody>
                </table>
              </div>
            </div>
          </div>
        </div>
      </div>
    </div>
  </div>
</div>
{/if}


