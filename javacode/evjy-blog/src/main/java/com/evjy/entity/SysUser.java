package com.evjy.entity;

import com.baomidou.mybatisplus.annotation.*;
import lombok.Data;

import java.io.Serial;
import java.io.Serializable;
import java.util.Date;

/**
 * @Author Evjy
 * @Date 2024/3/14 19:59
 * @Description 用户实体
 */
@TableName(value = "sys_user")
@Data
public class SysUser implements Serializable {

    @Serial
    @TableField(exist = false)
    private static final long serialVersionUID = 1L;

    /**
     * 主键 id，局部 id 自增
     */
    @TableId(type = IdType.AUTO)
    private Long userId;

    /**
     * 用户名（昵称）
     */
    private String userName;

    /**
     * 密码
     */
    private String password;

    /**
     * 手机号码
     */
    private String phoneNumber;

    /**
     * 邮箱
     */
    private String email;

    /**
     * 头像地址
     */
    private String avatar;

    /**
     * 账号状态（1正常 0停用）
     */
    private String status;

    /**
     * 创建时间
     */
    @TableField(fill = FieldFill.INSERT)
    private Date createTime;

    /**
     * 更新时间
     */
    @TableField(fill = FieldFill.INSERT_UPDATE)
    private Date updateTime;

    /**
     * 最后登录ip
     */
    private String lastLoginIp;

    /**
     * 最后登录时间
     */
    private Date lastLoginDate;

    /**
     * 逻辑删除标志（1存在 0删除）
     */
    private String logicDeleteFlag;

    public SysUser(String userName, String password) {
        this.userName = userName;
        this.password = password;
    }

}
