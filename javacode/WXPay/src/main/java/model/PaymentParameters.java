package model;

import lombok.AllArgsConstructor;
import lombok.Builder;
import lombok.Data;
import lombok.NoArgsConstructor;

/**
 * @Author Evjy
 * @Date 2024/4/13 12:45
 * @Description 支付参数
 */

@Data
@Builder
@AllArgsConstructor
@NoArgsConstructor
public class PaymentParameters {
    /**
     * 应用 id
     */
    private String appid;

    /**
     * 直连商户号
     */
    private String mchid;

    /**
     * 商品描述
     */
    private String description;

    /**
     * 商户订单号
     */
    private String out_trade_no;

    /**
     * 通知地址
     */
    private String notify_url;

    /**
     * 订单金额
     */
    private Amount amount;
}
