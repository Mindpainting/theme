package com.springboot;

import com.springboot.repository.IdiomRepository;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

@SpringBootTest
public class ApplicationTest {
    @Autowired
    private IdiomRepository idiomRepository;

    @Test
    public void test() {
        idiomRepository.queryAll();
    }
}
