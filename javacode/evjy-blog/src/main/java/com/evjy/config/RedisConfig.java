package com.evjy.config;

import com.evjy.common.toolkit.FastJson2RedisSerializer;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.data.redis.connection.RedisConnectionFactory;
import org.springframework.data.redis.core.RedisTemplate;
import org.springframework.data.redis.serializer.StringRedisSerializer;

/**
 * @Author Evjy
 * @Date 2024/3/21 16:03
 * @Description RedisConfig
 */
@Configuration
public class RedisConfig {

    @Bean
    public RedisTemplate<Object, Object> redisTemplate(RedisConnectionFactory redisConnectionFactory) {
        RedisTemplate<Object, Object> redisTemplate = new RedisTemplate<>();
        redisTemplate.setConnectionFactory(redisConnectionFactory);

        // 使用 FastJson2RedisSerializer 序列化 key 和 value
        FastJson2RedisSerializer<Object> serializer = new FastJson2RedisSerializer<>(Object.class);

        // 使用 StringRedisSerializer 来序列化和反序列化 redis 的 key 值
        redisTemplate.setKeySerializer(new StringRedisSerializer());
        redisTemplate.setHashKeySerializer(new StringRedisSerializer());

        // 使用 FastJson2RedisSerializerHash 来序列化和反序列化 redis 的 value 值
        redisTemplate.setValueSerializer(serializer);
        redisTemplate.setHashValueSerializer(serializer);

        // 在 Spring 容器完成 bean 实例化后，确保 RedisTemplate 对象的相关属性已经设置完毕，可以安全地进行后续操作
        redisTemplate.afterPropertiesSet();
        return redisTemplate;
    }

}