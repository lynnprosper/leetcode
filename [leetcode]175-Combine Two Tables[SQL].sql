/*
1. 原题
https://leetcode.com/problems/combine-two-tables/

2. 思路
查询表中数据，使用外联结即可。
*/
# Write your MySQL query statement below
SELECT pe.FirstName, pe.LastName, ad.City, ad.State
FROM Person AS pe LEFT OUTER JOIN Address AS ad
ON pe.PersonId = ad.PersonId
