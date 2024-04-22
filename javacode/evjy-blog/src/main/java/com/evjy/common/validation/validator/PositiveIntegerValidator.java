package com.evjy.common.validation.validator;

import com.evjy.common.validation.validate.PositiveInteger;
import jakarta.validation.ConstraintValidator;
import jakarta.validation.ConstraintValidatorContext;

/**
 * @Author Evjy
 * @Date 2024/4/19 16:14
 * @Description 正整数校验器
 */
public class PositiveIntegerValidator implements ConstraintValidator<PositiveInteger, Integer> {
    // 具体的校验逻辑，返回值表示校验是否通过
    @Override
    public boolean isValid(Integer value, ConstraintValidatorContext constraintValidatorContext) {
        /*
         * Integer.signum(value)
         * 负数 --> 返回 -1
         * 零 --> 返回 0
         * 正数 --> 返回 1
         */
        return value == null || (Integer.signum(value) > 0);
    }

    @Override
    public void initialize(PositiveInteger constraintAnnotation) {
        ConstraintValidator.super.initialize(constraintAnnotation);
    }
}
