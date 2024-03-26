package com.evjy;

import com.evjy.common.constant.Constants;
import com.evjy.common.toolkit.Jwt;
import com.evjy.common.toolkit.RedisCache;
import com.evjy.entity.ca.LoginUser;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

@SpringBootTest
class EvjyBlogApplicationTests {

    @Autowired
    RedisCache redisCache;

    @Test
    void contextLoads() throws Exception {
        String jwt = Jwt.generateJWT("2");
        System.out.println(jwt);
        System.out.println(Jwt.parseJWT(jwt));

        LoginUser user = new LoginUser();
        redisCache.setCacheObject(Constants.LOGIN_TOKEN_KEY_PREFIX + 2, user);
        LoginUser loginUser = redisCache.getCacheObject(Constants.LOGIN_TOKEN_KEY_PREFIX + 2);
        System.out.println(loginUser);
    }

}
