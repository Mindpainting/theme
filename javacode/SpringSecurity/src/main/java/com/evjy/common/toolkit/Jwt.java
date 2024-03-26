package com.evjy.common.toolkit;

import com.evjy.common.constant.Constants;
import com.evjy.entity.ca.LoginUser;
import io.jsonwebtoken.Jwts;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

import javax.crypto.SecretKey;
import java.util.Date;
import java.util.UUID;
import java.util.concurrent.TimeUnit;

/**
 * @Author Evjy
 * @Date 2024/3/15 16:40
 * @Description JWT
 */

@Component
public class Jwt {

    // 令牌有效期（默认30分钟）
    private static final int EXPIRES = 30;

    // 有效期 30 天
    public static final long TTL = 60 * 60 * 1000L * 24 * 30;

    // 1秒 = 1000毫秒
    protected static final long MILLIS_SECOND = 1000;

    // 1分钟 = 60 * 1000 毫秒
    protected static final long MILLIS_MINUTE = 60 * MILLIS_SECOND;

    // 签名密钥，生成，解析 JWT 需要保证使用的同一签名密钥，具有唯一性
    public static final SecretKey key = Jwts.SIG.HS512.key().build();

    @Autowired
    RedisCache redisCache;

    // 获取 UUID
    public static String getUUID() {
        return UUID.randomUUID().toString().replaceAll("-", "");
    }

    // 生成 JWT
    public static String generateJWT(String userId) {
        long currentTimeMillis = System.currentTimeMillis();
        return Jwts.builder()
            .id(getUUID())
            .issuer("Evjy")
            .signWith(key)
            .subject(userId)
            .issuedAt(new Date(currentTimeMillis))
            .expiration(new Date(currentTimeMillis + TTL))
            .compact();
    }

    // 解析 JWT
    public static String parseJWT(String jwt) {
        return Jwts.parser()
            .verifyWith(key)
            .build()
            .parseSignedClaims(jwt)
            .getPayload()
            .getSubject();
    }

    // 刷新令牌有效期
    public boolean refreshToken(LoginUser loginUser, int expires)
    {
        loginUser.setLoginTime(System.currentTimeMillis());
        loginUser.setExpires(loginUser.getLoginTime() + EXPIRES * MILLIS_MINUTE);
        String key = Constants.LOGIN_TOKEN_KEY_PREFIX + loginUser.getUser().getUserId();
        redisCache.setCacheObject(key, loginUser);
        return redisCache.setExpires(key, expires, TimeUnit.MINUTES);
    }

}
