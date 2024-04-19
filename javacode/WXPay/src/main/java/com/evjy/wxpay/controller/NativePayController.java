package com.evjy.wxpay.controller;

import com.evjy.wxpay.service.NativePayService;
import model.PaymentNotification;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.io.IOException;
import java.net.URISyntaxException;
import java.util.Map;

/**
 * @Author Evjy
 * @Date 2024/4/15 13:22
 * @Description TODO
 */

@RestController
@RequestMapping("/pay")
public class NativePayController {

    @Autowired
    private NativePayService nativePayService;

    @PostMapping("/createOrder")
    public void createOrder() {
        nativePayService.createOrder();
    }

    @GetMapping("/queryOrder")
    public void queryOrder() {
        try {
            nativePayService.queryOrder();
        } catch (IOException | URISyntaxException e) {
            throw new RuntimeException(e);
        }
    }

    @RequestMapping("/notify")
    public Map<String, String> notify(@RequestBody PaymentNotification paymentNotification) {
        return nativePayService.notify(paymentNotification);
    }
}
