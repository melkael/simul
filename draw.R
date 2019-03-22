modelname = "exo2.csv"
data = read.table(modelname)
attach(data);

temps = V1
moyenne = V2
png("plot.png")
plot(temps, moyenne, type="l", xlab="temps", ylab= "E[N]", col = "red")