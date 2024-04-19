package model;

import lombok.AllArgsConstructor;
import lombok.Builder;
import lombok.Data;
import lombok.NoArgsConstructor;

/**
 * @Author Evjy
 * @Date 2024/4/13 12:39
 * @Description 订单金额
 */

@Data
@Builder
@AllArgsConstructor
@NoArgsConstructor
public class Amount {
    /**
     * 订单总金额，单位为分
     */
    private Integer total;

    /**
     * 货币类型
     */
    private String currency;
}
