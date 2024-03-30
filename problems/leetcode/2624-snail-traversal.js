/**
 * @param {number} rowsCount
 * @param {number} colsCount
 * @return {Array<Array<number>>}
 */
Array.prototype.snail = function (rowsCount, colsCount) {
    if (this.length !== rowsCount * colsCount) {
        return [];
    }
    const matrix = Array.from({ length: rowsCount }).map((_) => []);
    let isTopDownDirection = true,
        matrixIndex = 0;
    for (let i = 0; i < this.length; i++) {
        matrix[matrixIndex].push(this[i]);
        if ((i + 1) % rowsCount === 0) {
            isTopDownDirection = !isTopDownDirection;
            continue;
        }
        matrixIndex += isTopDownDirection ? 1 : -1;
    }
    return matrix;
};

/**
 * const arr = [1,2,3,4];
 * arr.snail(1,4); // [[1,2,3,4]]
 */
