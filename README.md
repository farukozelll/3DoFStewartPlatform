# 3DoFStewartPlatform

# PROJE ÖZETİ
 Stewart Platform Mekanizması alt kısmı hareketsiz bir plakaya bağlı, üst kısmı ise uzaysal hareketi sağlaması amacıyla hazırlanmış bir uç işlevciye bağlı altı adet doğrusal tahrik elemanından oluşan; üç öteleme ve üç dönme hareketi yapmaya imkân veren paralel bir mekanizmadır. Bu mekanizma ilk olarak 1965 ‘de D.Stewart tarafından uçuş simülatörü olarak sunulmuş ve zamanla önemi artmıştır. Bu çalışmada Stewart Platformunun kinematik ve dinamik davranışları incelenmiş, bu davranışlar bilgisayar ortamında gerçek zamanlı olarak simüle edilmiştir.

Bu amaçlar:
1.Uçuş simülasyonları
2.Animatronik
3. Vinç teknolojisi
4. Sualtı araştırması
5.Deprem simülasyonları
6. Robotik vb.


#1. STEWART PLATFORMU NEDİR?   

Paralel manipülatörler, seri manipülatörlere göre çeşitli avantajlar gösterir. Örneğin, bir paralel manipülatör daha hassas bir şekilde kontrol edilebilir, çünkü hatalar tek bir bacağın içinde bulunur. Bir seri manipülatör ile, sert yapılardan birinin hareketindeki bir hata, takip eden yapıların her birinde çoğaltılır. Paralel manipülatörler, çok daha büyük ve daha ağır iş yüklerini kaldırabilir ve seri manipülatörlerden daha iyi kütle-kütle oranına sahiptir.
Stewart platformu olacak cihaz ilk kez 1954'te İngiltere'den V. Eric Gough tarafından tasarlandı. Lastiklerin testinde kullanılır. On yıldan kısa bir süre sonra, D. Stewart, İngiltere Makine Mühendisleri Enstitüsü'ne uçuş simülatörlerinde kullanılmak üzere ayarlanabilir bir platform öneren bir bildiri sundu.


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

# 1.1.	STEWART PLATFORM KONTROLÜ

Platformun kontrolü sağlanırken servo kollarına bağlı olan çubukların bağlantı noktaları alt platformun merkezine göre hesaplanır. Ardından üst platformun tellere bağlantı noktaları üst platformun merkezine göre hesaplanır. Ardından alt platformun “z” kadar üstünde bir rijit cisim olduğu kabul edilerek bu cismin konumu ve dönme açıları hesaplanarak servolara gerekli döndürme değerleri gönderilir. 
Döndürme hesabı üst platformun bağlantı noktası ile alt platformun bağlantı noktasını birleştiren telin uzunluğunun ne kadar olması gerektiği hesaplanarak sağlanır. Bu iki bağlantı noktası arasındaki fark Pisagor teoremi ile kolayca bulunur. Alt platform ile üst platform arasındaki X, Y, Z eksenleri uzaklıkları bulunup kareleri toplanıp karekökü alınarak gerekli uzaklık hesaplanır ve servonun o uzaklığı sağlaması için gereken sinyal elde edilmiş olur.

![1](https://user-images.githubusercontent.com/47918693/211142753-f84fbbc1-dd39-4a86-8462-22cd0aa17dc2.jpg)

# 2.1.1. ALT VE ÜST PLATFORM
Platform 3x3 çapraz bağlıdır.  Platformun bu şekilde seçilmesinin sebebi 3 adet servo motor ile gerçekleştirileceğinden motorlar arasındaki açının 120 derece olmasını sağlamaktır. Platformun alt ve üst plakaları SOLIDWORKS programı aracılığıyla çizilip 3D Printer ile hazırlanmıştır.
![4](https://user-images.githubusercontent.com/47918693/211142853-4a616e7b-3aca-4fd9-a0f4-6ed5cf175be1.jpg)

  #   2.2. BAĞLANTI ŞEMASI
  ![6](https://user-images.githubusercontent.com/47918693/211142807-549806fa-8c1d-4aa5-a5fd-607c1e68ec04.png)

# Platformun en son sürümü:
![5](https://user-images.githubusercontent.com/47918693/211142773-0dbda12e-8f09-4015-a1c0-1c5b1973f408.jpg)


