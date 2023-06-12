const math =  require("./build/Release/math")

class FMath {

  constructor(){}

  sumAll(...number) {
    math.sumAll(number)
  }

let package = new FMath()

package.sumAll(32, 321 ,312)
