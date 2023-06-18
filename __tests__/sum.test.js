import Fastmath from "../index.js";

test('Verify sum modules', () => {
  
  expect(Fastmath.sumAll).toBeTruthy();

});

test('Verify module ("sumAll()")', () => {
  
  expect(Fastmath.sumAll(1,2,3,4,5)).toBe(15)
})
