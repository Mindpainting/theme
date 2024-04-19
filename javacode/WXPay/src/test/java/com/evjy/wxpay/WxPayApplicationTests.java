package com.evjy.wxpay;

import com.alibaba.fastjson2.JSON;
import com.wechat.pay.contrib.apache.httpclient.WechatPayHttpClientBuilder;
import com.wechat.pay.contrib.apache.httpclient.auth.AutoUpdateCertificatesVerifier;
import com.wechat.pay.contrib.apache.httpclient.auth.PrivateKeySigner;
import com.wechat.pay.contrib.apache.httpclient.auth.WechatPay2Credentials;
import com.wechat.pay.contrib.apache.httpclient.auth.WechatPay2Validator;
import com.wechat.pay.contrib.apache.httpclient.util.PemUtil;
import model.Amount;
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
import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import org.springframework.boot.test.context.SpringBootTest;

import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.security.PrivateKey;

@SpringBootTest
class WxPayApplicationTests {

    // Because this usage is so common, Log4j 2 provides that as the default when the logger name parameter is either omitted or is null
    private static final Logger logger = LogManager.getLogger();

    private final String appId = "wxffb3637a228223b8";
    private final String mchId = "1561414331";

    /**
     * 商户私钥
     */
    private final String privateKey = "-----BEGIN PRIVATE KEY-----\nMIIEvQIBADANBgkqhkiG9w0BAQEFAASCBKcwggSjAgEAAoIBAQDBHGgIh80193Gh\ndpD1LtMZfTRpcWI0fImyuBCyrd3gYb3rrsARebGcHdJsQA3mVjVqVp5ybhEZDPa4\necoK4Ye1hTppNpI/lmLt4/uUV/zhF5ahli7hi+116Ty6svHSbuMQBuUZeTFOwGrx\njvofU/4pGIwh8ZvkcSnyOp9uX2177UVxDBkhgbZbJp9XF2b83vUa5eHo93CziPzn\n3hFdAlBCdTXB7DH+m0nN3Jou0szGukvq7cIgGpHku4ycKSTkIhhl9WRhN6OoSEJx\nq88MXzjkzTruc85PHN52aUTUifwg3T8Y4XqFQ61dTnEmgxeD2O6/pLdB9gLsp6yC\nGqN5Lqk7AgMBAAECggEBAL4X+WzUSbSjFS9NKNrCMjm4H1zgqTxjj6TnPkC1mGEl\ntjAHwLgzJBw62wWGdGhWWpSIGccpBBm1wjTMZpAZfF66fEpP1t1Ta6UjtGZNyvfF\nIZmE3jdWZ/WXGBnsxtFQKKKBNwrBW0Fbdqq9BQjLxLitmlxbmwrgPttcy855j6vZ\nqq4MBT1v8CtUT/gz4UWW2xWovVnmWOrRSScv7Nh0pMbRpPLkNHXrBwSSNz/keORz\nXB9JSm85wlkafa7n5/IJbdTml3A/uAgW3q3JZZQotHxQsYvD4Zb5Cnc9CPAXE5L2\nYk877kVXZMGt5QPIVcPMj/72AMtaJT67Y0fN0RYHEGkCgYEA38BIGDY6pePgPbxB\n7N/l6Df0/OKPP0u8mqR4Q0aQD3VxeGiZUN1uWXEFKsKwlOxLfIFIFk1/6zQeC0xe\ntNTKk0gTL8hpMUTNkE7vI9gFWws2LY6DE86Lm0bdFEIwh6d7Fr7zZtyQKPzMsesC\n3XV9sdSUExEi5o/VwAyf+xZlOXcCgYEA3PGZYlILjg3esPNkhDz2wxFw432i8l/B\nCPD8ZtqIV9eguu4fVtFYcUVfawBb0T11RamJkc4eiSOqayC+2ehgb+GyRLJNK4Fq\nbFcsIT+CK0HlscZw51jrMR0MxTc4RzuOIMoYDeZqeGB6/YnNyG4pw2sD8bIwHm84\n06gtJsX/v10CgYAo8g3/aEUZQHcztPS3fU2cTkkl0ev24Ew2XGypmwsX2R0XtMSB\nuNPNyFHyvkgEKK2zrhDcC/ihuRraZHJcUyhzBViFgP5HBtk7VEaM36YzP/z9Hzw7\nbqu7kZ85atdoq6xpwC3Yn/o9le17jY8rqamD1mv2hUdGvAGYsHbCQxnpBwKBgHTk\neaMUBzr7yZLS4p435tHje1dQVBJpaKaDYPZFrhbTZR0g+IGlNmaPLmFdCjbUjiPy\nA2+Znnwt227cHz0IfWUUAo3ny3419QkmwZlBkWuzbIO2mms7lwsf9G6uvV6qepKM\neVd5TWEsokVbT/03k27pQmfwPxcK/wS0GFdIL/udAoGAOYdDqY5/aadWCyhzTGI6\nqXPLvC+fsJBPhK2RXyc+jYV0KmrEv4ewxlK5NksuFsNkyB7wlI1oMCa/xB3T/2vT\nBALgGFPi8BJqceUjtnTYtI4R2JIVEl08RtEJwyU5JZ2rvWcilsotVZYwfuLZ9Kfd\nhkTrgNxlp/KKkr+UuKce4Vs=\n-----END PRIVATE KEY-----\n";

    /**
     * 商户证书序列号
     */
    private final String mchSerialNo = "25FBDE3EFD31B03A4377EB9A4A47C517969E6620";

    /**
     * V3 密钥
     */
    private final String apiV3Key = "CZBK51236435wxpay435434323FFDuv3";
    private CloseableHttpClient httpClient;

    @BeforeEach
    public void setup() {
        // 加载商户私钥（privateKey：私钥字符串）
        PrivateKey merchantPrivateKey = PemUtil.loadPrivateKey(new ByteArrayInputStream(privateKey.getBytes(StandardCharsets.UTF_8)));

        // 加载平台证书（mchId：商户号,mchSerialNo：商户证书序列号,apiV3Key：V3密钥）
        AutoUpdateCertificatesVerifier verifier = new AutoUpdateCertificatesVerifier(
            new WechatPay2Credentials(mchId, new PrivateKeySigner(mchSerialNo, merchantPrivateKey)), apiV3Key.getBytes(StandardCharsets.UTF_8));

        // 初始化httpClient
        httpClient = WechatPayHttpClientBuilder.create()
            .withMerchant(mchId, mchSerialNo, merchantPrivateKey)
            .withValidator(new WechatPay2Validator(verifier)).build();
    }

    @AfterEach
    public void after() throws IOException {
        httpClient.close();
    }

    @Test
    public void CreateOrder() throws Exception {
        HttpPost httpPost = new HttpPost("https://api.mch.weixin.qq.com/v3/pay/transactions/native");

        // 请求body参数
        Amount amount = Amount.builder()
            .total(1)
            .currency("CNY")
            .build();
        PaymentParameters nativePayParams = PaymentParameters.builder()
            .appid(appId)
            .mchid(mchId)
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
        }
    }


    @Test
    public void queryOrder() throws Exception {
        //请求URL
        URIBuilder uriBuilder = new URIBuilder("https://api.mch.weixin.qq.com/v3/pay/transactions/out-trade-no/Coral09091232");
        uriBuilder.setParameter("mchid", mchId);

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
                throw new IOException("request failed");
            }
        }
    }


    @Test
    public void logTest() {
        while (true){
            logger.trace("trace");
            logger.debug("debug");
            logger.info("info");
            logger.warn("warn");
            logger.error("error");
            logger.fatal("fatal");
        }
    }


}
