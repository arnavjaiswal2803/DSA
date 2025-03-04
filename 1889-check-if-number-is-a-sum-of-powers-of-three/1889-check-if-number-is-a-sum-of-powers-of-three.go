func checkPowersOfThree(n int) bool {
    power := 0
    for int(math.Pow(3, float64(power))) <= n {
        power++
    }
    power--;

    for power >= 0 && n > 0  {
        threeRaisedToPower := int(math.Pow(3, float64(power)))
        if n >= threeRaisedToPower {
            n -= threeRaisedToPower
        }
        power--
    }

    return n == 0
}