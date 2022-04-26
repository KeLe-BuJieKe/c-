/*69. x 的平方根 
给你一个非负整数 x ，计算并返回 x 的 算术平方根 。
由于返回类型是整数，结果只保留 整数部分 ，小数部分将被 舍去 。
注意：不允许使用任何内置指数函数和算符，例如 pow(x, 0.5) 或者 x ** 0.5 。
示例 1：
输入：x = 4
输出：2

示例 2：
输入：x = 8
输出：2
解释：8 的算术平方根是 2.82842..., 由于返回类型是整数，小数部分将被舍去。
提示：
0 <= x <= 2^31 - 1
*/



//二分法
class Solution {
public:
    int mySqrt(int x) {
        long double left = 0;
        long double right = x;
        long double mid = 0;
        while ((right - left) >= 1e-7) {
            mid = ((right - left) / 2 ) + left;
            if ((mid * mid) <= x) {
                left = mid;
            }
            else {
                right = mid;
            }
        }
        mid = std::ceil(mid) - mid > 1e-7 ? mid : std::ceil(mid);
        return mid;
    }
};
