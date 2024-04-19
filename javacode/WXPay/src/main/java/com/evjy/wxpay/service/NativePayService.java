package com.evjy.wxpay.service;

import model.PaymentNotification;

import java.io.IOException;
import java.net.URISyntaxException;
import java.util.Map;

/**
 * @Author Evjy
 * @Date 2024/4/15 14:08
 * @Description TODO
 */

public interface NativePayService {
    Map<String, String> notify(PaymentNotification paymentNotification);

    void createOrder();

    void queryOrder() throws IOException, URISyntaxException;
}
