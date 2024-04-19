package model;

import lombok.Data;

/**
 * @Author Evjy
 * @Date 2024/4/15 13:35
 * @Description 支付通知参数
 */

@Data
public class PaymentNotification {
    private String id;
    private String create_time;
    private String event_type;
    private String resource_type;
    /**
     * 通知数据
     */
    private Resource resource;
    private String summary;
}
