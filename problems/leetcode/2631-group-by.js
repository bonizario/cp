/**
 * @param {Function} fn
 * @return {Object}
 */
Array.prototype.groupBy = function (fn) {
  return this.reduce((group, item) => {
      const key = fn(item);
      if (!group.hasOwnProperty(key)) {
          group[key] = [];
      }
      group[key].push(item);
      return group
  }, {});
};

/**
* [1,2,3].groupBy(String) // {"1":[1],"2":[2],"3":[3]}
*/
