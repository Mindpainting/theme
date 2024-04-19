package com.evjy.common.toolkit;

import com.evjy.common.constant.JwtEnum;
import com.evjy.model.LoginUser;
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

    // 生成一个随机的 key ，但是，每次项目启动之后，之前生成的 jwt 将无法解析
    public static final SecretKey SECRET_KEY = Jwts.SIG.HS512.key().build();

    // 签名密钥，生成，解析 JWT 需要保证使用的同一签名密钥，具有唯一性
    // public static final String SECRET_KEY = "CoralIsland";

    // 1秒 = 1000毫秒
    protected static final long MILLIS_SECOND = 1000;

    // 1分钟 = 60 * 1000 毫秒
    protected static final long MILLIS_MINUTE = 60 * MILLIS_SECOND;

    // 1小时 = 60 * 60 * 1000 毫秒
    protected static final long MILLIS_HOUR = 60 * MILLIS_SECOND;

    // 1天 = 24 * 60 * 60 * 1000 毫秒
    protected static final long MILLIS_DAY = 24 * MILLIS_HOUR;
    // 有效期 30 天
    public static final long TTL = 30 * MILLIS_DAY;
    // 令牌有效期（默认30天）
    private static final int EXPIRES = 30;
    @Autowired
    RedisCache redisCache;

    // 获取 UUID
    public static String getUUID() {
        return UUID.randomUUID().toString().replaceAll("-", "");
    }

    // 生成 Token
    public static String generateToken(String userId) {
        long currentTimeMillis = System.currentTimeMillis();
        return Jwts.builder()
            .header()
            //.keyId("HS512")
            //.add("header", "header")
            .and()
            .id(getUUID())
            .issuer("Evjy")
            .signWith(SECRET_KEY)
            .subject(userId)
            .issuedAt(new Date(currentTimeMillis))
            .expiration(new Date(currentTimeMillis + TTL))
            .compact();
    }

    // 解析 Token
    public static String parseToken(String jwt) {
        return Jwts.parser()
            .verifyWith(SECRET_KEY)
            .build()
            .parseSignedClaims(jwt)
            .getPayload()
            .getSubject();
    }

    // 刷新令牌有效期
    public boolean refreshToken(LoginUser loginUser, int expires) {
        loginUser.setLoginTime(System.currentTimeMillis());
        loginUser.setExpires(loginUser.getLoginTime() + EXPIRES * MILLIS_DAY);
        String key = JwtEnum.LOGIN_TOKEN_KEY_PREFIX.getValue() + loginUser.getAuthUser().getUserId();
        redisCache.setCacheObject(key, loginUser);
        return redisCache.setExpires(key, expires, TimeUnit.MINUTES);
    }

}
