import Fastmath from "../index.js";

test('Verify sum modules', () => {
  expect(Fastmath.sumAll(1,2,3,4,5,6,7,8)).toBe(36);
});
