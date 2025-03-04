func romanToInt(s string) int {
    n, convertedNum := len(s), 0
    for i := 0; i < n; i++ {
        ch := s[i]
        if ch == 'I' {
            if i < n - 1 && s[i + 1] == 'V' {
                convertedNum += 4
                i++
            } else if i < n - 1 && s[i + 1] == 'X' {
                convertedNum += 9
                i++
            } else {
                convertedNum += 1
            }
        } else if ch == 'V' {
            convertedNum += 5
        } else if ch == 'X' {
            if i < n - 1 && s[i + 1] == 'L' {
                convertedNum += 40
                i++
            } else if i < n - 1 && s[i + 1] == 'C' {
                convertedNum += 90
                i++
            } else {
                convertedNum += 10
            }
        } else if ch == 'L' {
            convertedNum += 50
        } else if ch == 'C' {
            if i < n - 1 && s[i + 1] == 'D' {
                convertedNum += 400
                i++
            } else if i < n - 1 && s[i + 1] == 'M' {
                convertedNum += 900
                i++
            } else {
                convertedNum += 100
            }
        } else if ch == 'D' {
            convertedNum += 500
        } else {
            convertedNum += 1000
        }
    }

    return convertedNum
}