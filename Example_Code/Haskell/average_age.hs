data Employee = Employee{
    name :: String,
    gender :: String,
    age :: Int
}

--Function to split the employee string into tokens
splitBang :: String -> [String]
splitBang [] = []
splitBang xs = s1 : splitBang (drop 1 s2) --concatenates everything before the first |
    where (s1,s2) = span (/= '|') xs      --then calls the function on everything after it

--Test String for splitBang
splitBangTest :: String
splitBangTest = "Phedra Skinner | Full | 53902 | Male | 31"

--Note: we do not care about salary in this portion
convertToEmployee :: [String] -> Employee
convertToEmployee [n,_,_,g,a] = Employee n g (read a)

getAverage :: [Int] -> Double
getAverage ages = fromIntegral (sum ages) / fromIntegral (length ages)

getAverageTotal :: [Employee] -> Double
getAverageTotal = getAverage . map age

main :: IO ()
main = do
        file <- readFile "../employees.txt"
        print (getAverageTotal $ map (convertToEmployee . splitBang) $ lines file)