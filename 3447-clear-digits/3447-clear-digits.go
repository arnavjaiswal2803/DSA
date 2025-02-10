func clearDigits(s string) string {
    n, skip, ans := len(s), 0, ""

    for i := n - 1; i >= 0; i-- {
        if unicode.IsDigit(rune(s[i])) {
            skip++
        } else if skip == 0 {
            ans += string(s[i])
        } else {
            skip--
        }
    }

    ans = reverse(ans)

    return ans
}

func reverse(str string) string {
    runes := []rune(str)
    for i, j := 0, len(runes) - 1; i < j; i, j = i + 1, j - 1 {
        runes[i], runes[j] = runes[j], runes[i]
    }
    return string(runes)
}