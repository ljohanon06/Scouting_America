import qualified System.Random.MWC.Probability as P
import Control.Monad.Primitive
import Data.Char (toLower)
import Data.Bool (bool)
import Control.Monad (replicateM)

getAge :: PrimMonad m => P.Gen (PrimState m) -> m Int
getAge gen = do
                x <- P.sample (P.gamma 3.0 5.0) gen
                return (18 + round x)

getWagesFull :: PrimMonad m => P.Gen (PrimState m) -> m Int
getWagesFull gen = do
                    x <- P.sample (P.pareto 2.4815 40000.0) gen
                    return (round (x :: Double))

getPartTimeHours :: PrimMonad m => P.Gen (PrimState m) -> m Int
getPartTimeHours = P.sample (P.uniformR (15,35))

getWagesPart :: PrimMonad m => P.Gen (PrimState m) -> m Int
getWagesPart gen = do
                    x <- P.sample (P.pareto 2.626 10) gen
                    return (round (x :: Double))

getName :: PrimMonad m => [String] -> [String] -> P.Gen (PrimState m) -> m String
getName firstNames lastNames gen = do
                                    fIndex <- P.sample (P.uniformR (0,4946)) gen
                                    lIndex <- P.sample (P.uniformR (0,1001)) gen
                                    return ((firstNames !! fIndex) ++ " " ++ (\(s:ss) -> s: map toLower ss) (lastNames !! lIndex))

coinFlip :: PrimMonad m => P.Gen (PrimState m) -> m Bool
coinFlip = P.sample (P.bernoulli 0.5)

getWage :: PrimMonad m => P.Gen (PrimState m) -> m String -- Either "Full | xxxx" or "Part | hours-wage"
getWage gen = do 
                fullTime <- coinFlip gen
                if fullTime then do
                    wage <- getWagesFull gen
                    return ("Full | " ++ show wage)
                else do
                    hour <- getPartTimeHours gen
                    wage <- getWagesPart gen
                    return ("Part | " ++ show hour ++ "-" ++ show wage)

getEmployee :: PrimMonad m => [String] -> [String] -> P.Gen (PrimState m) -> m String
getEmployee firstNames lastNames gen = do
                                        name <- getName firstNames lastNames gen
                                        male <- coinFlip gen
                                        wage <- getWage gen
                                        age <- getAge gen
                                        return (name ++ " | " ++ wage ++ " | " ++ bool "Male" "Female" male ++ " | " ++ show age)

main :: IO ()
main = do
        gen <- P.createSystemRandom
        f <- readFile "first-names.txt"
        l <- readFile "last-names.txt"
        let firstNames = lines f
        let lastNames = lines l
        emp <- replicateM 3000000 (getEmployee firstNames lastNames gen)
        writeFile "employees.txt" (unlines emp)

        
