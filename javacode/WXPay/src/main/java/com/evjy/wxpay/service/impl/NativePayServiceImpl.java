package com.evjy.wxpay.service.impl;

import com.alibaba.fastjson2.JSON;
import com.evjy.wxpay.constant.WxPayEnum;
import com.evjy.wxpay.service.NativePayService;
import com.wechat.pay.contrib.apache.httpclient.WechatPayHttpClientBuilder;
import com.wechat.pay.contrib.apache.httpclient.auth.AutoUpdateCertificatesVerifier;
import com.wechat.pay.contrib.apache.httpclient.auth.PrivateKeySigner;
import com.wechat.pay.contrib.apache.httpclient.auth.WechatPay2Credentials;
import com.wechat.pay.contrib.apache.httpclient.auth.WechatPay2Validator;
import com.wechat.pay.contrib.apache.httpclient.util.AesUtil;
import com.wechat.pay.contrib.apache.httpclient.util.PemUtil;
import lombok.extern.slf4j.Slf4j;
import model.Amount;
import model.PaymentNotification;
import model.PaymentParameters;
import org.apache.http.client.methods.CloseableHttpResponse;
import org.apache.http.client.methods.HttpGet;
import org.apache.http.client.methods.HttpPost;
import org.apache.http.client.utils.URIBuilder;
import org.apache.http.entity.StringEntity;
import org.apache.http.impl.client.CloseableHttpClient;
import org.apache.http.util.EntityUtils;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;
import org.springframework.stereotype.Service;

import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.net.URISyntaxException;
import java.nio.charset.StandardCharsets;
import java.security.GeneralSecurityException;
import java.security.PrivateKey;
import java.util.Map;

/**
 * @Author Evjy
 * @Date 2024/4/15 14:14
 * @Description TODO
 */

@Service
@Slf4j
public class NativePayServiceImpl implements NativePayService {
    private final CloseableHttpClient httpClient;

    public NativePayServiceImpl() {
        log.info("NativePay Initialize...");
        // 加载商户私钥（privateKey：私钥字符串）
        PrivateKey merchantPrivateKey = PemUtil.loadPrivateKey(new ByteArrayInputStream(WxPayEnum.PRIVATE_KEY.getValue().getBytes(StandardCharsets.UTF_8)));

        // 加载平台证书（mchId：商户号,mchSerialNo：商户证书序列号,apiV3Key：V3密钥）
        AutoUpdateCertificatesVerifier verifier = new AutoUpdateCertificatesVerifier(
            new WechatPay2Credentials(WxPayEnum.MCHID.getValue(), new PrivateKeySigner(WxPayEnum.MCH_SERIAL_NO.getValue(), merchantPrivateKey)), WxPayEnum.API_V3_KEY.getValue().getBytes(StandardCharsets.UTF_8));

        // 初始化httpClient
        this.httpClient = WechatPayHttpClientBuilder.create()
            .withMerchant(WxPayEnum.MCHID.getValue(), WxPayEnum.MCH_SERIAL_NO.getValue(), merchantPrivateKey)
            .withValidator(new WechatPay2Validator(verifier)).build();
        log.info("NativePay Initialized");
    }

    @Override
    public void createOrder() {
        HttpPost httpPost = new HttpPost("https://api.mch.weixin.qq.com/v3/pay/transactions/native");

        // 请求body参数
        Amount amount = Amount.builder()
            .total(1)
            .currency("CNY")
            .build();
        PaymentParameters nativePayParams = PaymentParameters.builder()
            .appid(WxPayEnum.APPID.getValue())
            .mchid(WxPayEnum.MCHID.getValue())
            .description("商品描述")
            .out_trade_no("Coral09091232")
            .notify_url("https://4db0855f.r23.cpolar.top/pay/notify")
            .amount(amount)
            .build();

        String reqData = JSON.toJSONString(nativePayParams);
        StringEntity entity = new StringEntity(reqData, "utf-8");
        entity.setContentType("application/json");
        httpPost.setEntity(entity);
        httpPost.setHeader("Accept", "application/json");

        //完成签名并执行请求
        try (CloseableHttpResponse response = httpClient.execute(httpPost)) {
            int statusCode = response.getStatusLine().getStatusCode();
            if (statusCode == 200) { //处理成功
                System.out.println("success,return body = " + EntityUtils.toString(response.getEntity()));
            } else if (statusCode == 204) { //处理成功，无返回Body
                System.out.println("success");
            } else {
                System.out.println("failed,resp code = " + statusCode + ",return body = " + EntityUtils.toString(response.getEntity()));
                throw new IOException("request failed");
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    @Override
    public void queryOrder() throws URISyntaxException {
        //请求URL
        URIBuilder uriBuilder = new URIBuilder("https://api.mch.weixin.qq.com/v3/pay/transactions/out-trade-no/Coral09091232");
        uriBuilder.setParameter("mchid", WxPayEnum.MCHID.getValue());

        //完成签名并执行请求
        HttpGet httpGet = new HttpGet(uriBuilder.build());
        httpGet.addHeader("Accept", "application/json");
        try (CloseableHttpResponse response = httpClient.execute(httpGet)) {
            int statusCode = response.getStatusLine().getStatusCode();
            if (statusCode == 200) { //处理成功
                System.out.println("success,return body = " + EntityUtils.toString(response.getEntity()));
            } else if (statusCode == 204) { //处理成功，无返回Body
                System.out.println("success");
            } else {
                System.out.println("failed,resp code = " + statusCode + ",return body = " + EntityUtils.toString(response.getEntity()));
                try {
                    throw new IOException("request failed");
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    @Override
    public Map<String, String> notify(PaymentNotification paymentNotification) {
        Map<String, String> res = null;
        // 解密微信支付通知参数
        try {
            String json = new AesUtil(WxPayEnum.API_V3_KEY.getValue().getBytes()).decryptToString(paymentNotification.getResource().getAssociated_data().getBytes(), paymentNotification.getResource().getNonce().getBytes(), paymentNotification.getResource().getCiphertext());
            // 订单号
            String outTradeNo = JSON.parseObject(json, Map.class).get("out_trade_no").toString();
            System.out.println("outTradeNo = " + outTradeNo);
        } catch (GeneralSecurityException e) {
            res = Map.of("code", "FAIL", "message", "失败");
            throw new RuntimeException(e);
        }
        return res;
    }

}
