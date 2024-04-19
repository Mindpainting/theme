package com.evjy.wxpay.constant;

import lombok.AllArgsConstructor;
import lombok.Getter;

@Getter
@AllArgsConstructor
public enum WxPayEnum {
    /**
     * 应用 id
     */
    APPID("wxffb3637a228223b8"),

    /**
     * 商户号
     */
    MCHID("1561414331"),

    /**
     * 商户私钥
     */
    PRIVATE_KEY("-----BEGIN PRIVATE KEY-----\nMIIEvQIBADANBgkqhkiG9w0BAQEFAASCBKcwggSjAgEAAoIBAQDBHGgIh80193Gh\ndpD1LtMZfTRpcWI0fImyuBCyrd3gYb3rrsARebGcHdJsQA3mVjVqVp5ybhEZDPa4\necoK4Ye1hTppNpI/lmLt4/uUV/zhF5ahli7hi+116Ty6svHSbuMQBuUZeTFOwGrx\njvofU/4pGIwh8ZvkcSnyOp9uX2177UVxDBkhgbZbJp9XF2b83vUa5eHo93CziPzn\n3hFdAlBCdTXB7DH+m0nN3Jou0szGukvq7cIgGpHku4ycKSTkIhhl9WRhN6OoSEJx\nq88MXzjkzTruc85PHN52aUTUifwg3T8Y4XqFQ61dTnEmgxeD2O6/pLdB9gLsp6yC\nGqN5Lqk7AgMBAAECggEBAL4X+WzUSbSjFS9NKNrCMjm4H1zgqTxjj6TnPkC1mGEl\ntjAHwLgzJBw62wWGdGhWWpSIGccpBBm1wjTMZpAZfF66fEpP1t1Ta6UjtGZNyvfF\nIZmE3jdWZ/WXGBnsxtFQKKKBNwrBW0Fbdqq9BQjLxLitmlxbmwrgPttcy855j6vZ\nqq4MBT1v8CtUT/gz4UWW2xWovVnmWOrRSScv7Nh0pMbRpPLkNHXrBwSSNz/keORz\nXB9JSm85wlkafa7n5/IJbdTml3A/uAgW3q3JZZQotHxQsYvD4Zb5Cnc9CPAXE5L2\nYk877kVXZMGt5QPIVcPMj/72AMtaJT67Y0fN0RYHEGkCgYEA38BIGDY6pePgPbxB\n7N/l6Df0/OKPP0u8mqR4Q0aQD3VxeGiZUN1uWXEFKsKwlOxLfIFIFk1/6zQeC0xe\ntNTKk0gTL8hpMUTNkE7vI9gFWws2LY6DE86Lm0bdFEIwh6d7Fr7zZtyQKPzMsesC\n3XV9sdSUExEi5o/VwAyf+xZlOXcCgYEA3PGZYlILjg3esPNkhDz2wxFw432i8l/B\nCPD8ZtqIV9eguu4fVtFYcUVfawBb0T11RamJkc4eiSOqayC+2ehgb+GyRLJNK4Fq\nbFcsIT+CK0HlscZw51jrMR0MxTc4RzuOIMoYDeZqeGB6/YnNyG4pw2sD8bIwHm84\n06gtJsX/v10CgYAo8g3/aEUZQHcztPS3fU2cTkkl0ev24Ew2XGypmwsX2R0XtMSB\nuNPNyFHyvkgEKK2zrhDcC/ihuRraZHJcUyhzBViFgP5HBtk7VEaM36YzP/z9Hzw7\nbqu7kZ85atdoq6xpwC3Yn/o9le17jY8rqamD1mv2hUdGvAGYsHbCQxnpBwKBgHTk\neaMUBzr7yZLS4p435tHje1dQVBJpaKaDYPZFrhbTZR0g+IGlNmaPLmFdCjbUjiPy\nA2+Znnwt227cHz0IfWUUAo3ny3419QkmwZlBkWuzbIO2mms7lwsf9G6uvV6qepKM\neVd5TWEsokVbT/03k27pQmfwPxcK/wS0GFdIL/udAoGAOYdDqY5/aadWCyhzTGI6\nqXPLvC+fsJBPhK2RXyc+jYV0KmrEv4ewxlK5NksuFsNkyB7wlI1oMCa/xB3T/2vT\nBALgGFPi8BJqceUjtnTYtI4R2JIVEl08RtEJwyU5JZ2rvWcilsotVZYwfuLZ9Kfd\nhkTrgNxlp/KKkr+UuKce4Vs=\n-----END PRIVATE KEY-----\n"),

    /**
     * 商户证书序列号
     */
    MCH_SERIAL_NO("25FBDE3EFD31B03A4377EB9A4A47C517969E6620"),

    /**
     * V3 密钥
     */
    API_V3_KEY("CZBK51236435wxpay435434323FFDuv3");

    private final String value;
}
