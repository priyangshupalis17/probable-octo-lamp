/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(a, target) {
    let m = {};
    for (let i=0; i < a.length; i++) {
        let reqd = target - a[i];
        if(m[reqd] >= 0) {
            return [i, m[reqd]];
        }
        m[a[i]] = i;
    }
    return [];
};
