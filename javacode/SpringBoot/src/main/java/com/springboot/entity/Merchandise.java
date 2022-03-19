package com.springboot.entity;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@Data
@AllArgsConstructor
@NoArgsConstructor
public class Merchandise {
    private Integer id;
    private String category;
    private Double price;
    private Integer amount;
}
