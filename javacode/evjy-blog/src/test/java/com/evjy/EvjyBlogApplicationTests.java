package com.evjy;

import com.evjy.common.toolkit.RedisCache;
import com.evjy.entity.SysUser;
import com.evjy.mapper.SysUserMapper;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

@SpringBootTest
class EvjyBlogApplicationTests {

    private static final Logger logger = LoggerFactory.getLogger(EvjyBlogApplicationTests.class);

    @Autowired
    RedisCache redisCache;

    @Autowired
    SysUserMapper sysUserMapper;

    @Test
    void contextLoads() throws Exception {
        System.out.println(sysUserMapper.insert(new SysUser("Coral", "123456")));
    }

    @Test
    void testLogback() {
        logger.error("error");
        System.out.println(1);
        logger.debug("debug");
        logger.warn("warn");
        System.out.println(2);
        logger.trace("trace");
        System.out.println(3);
        System.out.println(4);
//        while (true) {
//            logger.info("{}", "info");
//        }
    }

}
