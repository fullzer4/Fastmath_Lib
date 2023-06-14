import { FSumAll } from "../core/sumops.js"

class IFastmath {
  constructor(){}

  sumAll(...number){    
    let result = FSumAll(number)
    return result
  }
  
}

export default IFastmath
