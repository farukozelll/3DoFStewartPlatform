# 3DoFStewartPlatform# 3DOF Stewart Platform 
 3 eksende hareket eden bir stewart platformu tasarlanmış ve kodlanmıştır.Stewart Platformları hareket ve konumlandırma için oluşturulmuş paralel manipülatörlerdir. Platform, 2 plaka arasında plakaların hareketini ve kontrolünü sağlamak için 6 adet ayarlanabilir ayak içerir. Platformun temel amacı, belirli amaçlar için bir test ortamı oluşturmaktır.
Bu amaçlar:
1.Uçuş simülasyonları
2.Animatronik
3. Vinç teknolojisi
4. Sualtı araştırması
5.Deprem simülasyonları
6. Robotik vb.

![image](https://user-images.githubusercontent.com/66810191/170566531-6cf9c466-d72b-48c8-8d9f-929fe52a0162.png)

İlk olarak 1949'da V. Eric Gough tarafından farklı yükleri test etmek için üretilen paralel bir mekanizma olarak ortaya çıktı. Sonra 1965'te D. Stewart, uçuş simülatörleri için hexapod'un bir varyantını kullanmaya başladı. Ve Gough-Stewart platformu adı altında Stewart platformu olarak anılmaya başlandı. Bu platform zaman içinde Klaus Cappel, H. McCallion vb. tarafından geliştirilmiştir. Birçok mühendis tarafından geliştirilip iyileştirilmeye çalışılarak günümüze kadar gelmiştir.

![image](https://user-images.githubusercontent.com/66810191/170566605-4447188a-4844-4cb6-b166-51a75327fe82.png)

## Stewart Platformunun Kinematiği
Stewart platformu 2 parçaya bağlıdır. Bu parçalar taban ve platform parçalarıdır. Bu parçalar birbirine 6 adet hesaplanmış ayak ile bağlanmıştır. Bu kurulum ile platform 3 öteleme ve dönme boyutunda hareket edebilir.
Taban parçası x y z ortogonal eksenleri ve referans çalışması olarak kabul edilir.
Platformun kendi x', y', z' ortogonal eksenleri vardır.
Platformun koordinatlarının orijini, tabanın her eksenine göre 1 kez olmak üzere 3 öteleme hareketi ile tanımlanır.
3 açısal yer değiştirme, taban platformuna göre yönü tanımlar. Aşağıdaki sırayla bir dizi Euler açısı kullanılır:
1. ψ açısını z ekseni etrafında döndürün.
2. θ açısını y ekseni etrafında döndürün.
3. φ açısını x ekseni etrafında döndürün.

![image](https://user-images.githubusercontent.com/66810191/170566726-efe7919c-3f49-4f4b-a191-bf95a074fff0.png)

P = i’x’ + j’y’ + k’z’ = ix + jy + kz
x = OA – BC = x’cos ψ – y’sin ψ 
y = AB + PC = x’sin ψ + y’cos ψ
z = z’

### Tabana göre platformun tam dönüş matrisi:
![image](https://user-images.githubusercontent.com/66810191/170566882-5a39b6c2-62e3-4a66-b0dd-612048d01f7c.png)

# Platformun en son sürümü:

![image](https://user-images.githubusercontent.com/66810191/170566992-c665df26-7007-42f3-a0ce-fc319bc9459d.png)
