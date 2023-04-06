# algoritma_odev_2.1

<h2>Amaç</h2>
<p>Bu programın amacı, bir binary tree'nin sol alt ağacını, sağ alt ağacını ve kendisini tek bir sıralı listede birleştirmektir.</p>

<h2>Açıklamalar</h2>
<p>Program, öncelikle verilen root düğümüne ait sol alt ağacı ziyaret eder ve sol alt ağacın en sağ düğümünü root düğümüne bağlar. Daha sonra, root düğümünün sol alt ağacına NULL atanır ve sağ alt ağacı ziyaret edilir. Sağ alt ağaçta benzer işlemler yapılır ve sonuçta birleştirilmiş sıralı liste elde edilir.</p>

<h2>Nasıl Kullanılır?</h2>
<p>Kodu kullanmak için, main fonksiyonunda bir binary tree oluşturmanız ve ardından flatten fonksiyonunu çağırmanız gerekiyor. Oluşturulan binary tree, struct dugum yapısı kullanılarak tanımlanır ve ağaç düzleştirildikten sonra printList fonksiyonu kullanılarak ekrana yazdırılır.</p>
