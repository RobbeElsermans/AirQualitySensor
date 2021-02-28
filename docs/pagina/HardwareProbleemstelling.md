# Hardware probleemstelling
### hardware schema consept

<img src="./picture/schema hardware consept.png">

---------------

### microcontroller
<p>We maken gebruik van de ESP32, aangezien deze werkt met de gewone arduino wifi libraries.
Het is mogelijk dat we later naar de ESP12f (ESP8266 familie) overschakelen. Aangezien deze minder verbruiken en minder kosten.</p>
* <a target="_blank" href="https://makeradvisor.com/esp32-vs-esp8266/">Verschil tussen ESP32 & ESP8266</a> 
<img src="./picture/ESP32_Pinout.jpg">

### sensoren
<p>In onze opstelling gaan we CO, CO², luchtvichtigheid, temperatuur, luchtkwaliteit en fijnstof meten. Hiervoor bestaan verschillende soorten sensoren die elk hun eigen voor en nadelen hebben. Voor de eenvoud van de meetingen gaan we er een GPS coördinaat bijplaatsen zodat het makkelijk in kaart gebracht kan worden.</p>
<p>In onderstaande tabel gaan we elk bespreken en beargumenteren waarom ze beter zijn dan anderen, de voordelen, eigenschappen en eventuele tegenhangers. Bij elke module, die we fysiek konden testen, is er een sketch beschikbaar in de repository onder <a target="_blank" href="https://github.com/RobbeElsermans/AirQualitySensor/tree/main/Arduino%20program/onderzoek"><i>Arduino program/onderzoek</i></a>.</p>
</br>
</br>

<table>
<tr>
    <th>Naam</th>
    <th>Eigenschappen</th>
    <th>argumentatie</th>
    <th>website</th>
</tr>
<tr>
    <td>MQ-7</td>
    <td>
        <ul>
            <li><b>CO gas sensor</b></li>
            <li>V<sub>cc</sub> = 5V</li>
            <li>I<sub>max</sub> = 350mA</li>
            <li>analoge uitgang van 0V-5V</li>
            <li>digitale uitgang instelbaar via trim</li>
            <li>voorverwarm tijd: 48 uur</li>
            <li>meetbereik: 20ppm<sup>1</sup>-2000ppm</li>
            <li>leessnelheid = continue</li>
        </ul>
    </td>
    <td>De MQ-7 is een wijd gebruikte sensor in de IoT wereld. Deze is traag maar wel nauwkeurig als je er een wachtijd opplakt van zeker 4 min. De datasheet schrijft voor om de sensor voor te verwarmen voor 48 uur. Wat tamelijk lang is. Voor een opstelling die ergens op een vaste locatie staat waar continue stroom naar geleverd wordt, is het zeker een goede keuzen om te gebruiken.</td>
    <td><a target="_blank" href="https://www.tinytronics.nl/shop/nl/sensoren/mq-7-gas-sensor-module">link</a></td>
</tr>
<tr>
    <td>MQ-135</td>
    <td>        
        <ul>
            <li><b>CO² gas sensor</b></li>
            <li>V<sub>cc</sub> = 5V</li>
            <li>I<sub>max</sub> = 800mW</li>
            <li>analoge uitgang van 0V-5V</li>
            <li>digitale uitgang instelbaar via trim</li>
            <li>voorverwarm tijd: 24 uur</li>
            <li>meetbereik: 10ppm-200ppm</li>
            <li>leessnelheid = continue</li>
        </ul>
    </td>
    <td>Deze argumentatie is idem als de MQ-7. zeer nauwkeurig mits lange opwarm tijd</td>
    <td><a target="_blank" href="https://www.tinytronics.nl/shop/nl/sensoren/mq-135-gas-sensor-module">link</a></td>
</tr>
<tr>
    <td>DHT22</td>
    <td>        
        <ul>
            <li><b>Temperatuur & luchtvochtigheid</b></li>
            <li>V<sub>cc</sub> = 3.3V-5V</li>
            <li>I<sub>max</sub> = 1.5mA</li>
            <li><a target="_blank" href="https://en.wikipedia.org/wiki/1-Wire">OneWire</a> protocol 3.3V-5V</li>
            <li>meetbereik temperatuur: -40°C ~ +80°C - 0.5°C afwijking</li>
            <li>meetbereik luchtvochtigheid: 0% ~ 100% - 2% afwijking</li>
            <li>leessnelheid = 2s of meer</li>
        </ul>
    </td>
    <td>De bekende DHT22 is de sterkere variant van DHT11. Hij heeft een groote bereik van temperatuur. Enkel zegt men dat deze onbetrouwbaar is in tijd. Maar voor een gewone temperatuurmeting zonder criticaal proces hieraan vast, is hij zeker goed genoeg. </td>
    <td><a target="_blank" href="https://www.tinytronics.nl/shop/nl/sensoren/dht22-thermometer-temperatuur-en-vochtigheids-sensor">link</a></td>
</tr>
<tr>
    <td>CCS811</td>
    <td>
        <ul>
            <li><b>temperatuur, eCO² en eTVOC<sup>2</sup></b></li>
            <li>V<sub>cc</sub> = 1.8V-3.3V</li>
            <li>I<sub>max</sub> = 54mA</li>
            <li><a target="_blank" href="https://en.wikipedia.org/wiki/I%C2%B2C">I²C</a> protocol 3.3V</li>
            <li>meetbereik temperatuur: -40°C ~ +85°C</li>
            <li>meetbereik luchtvochtigheid: 10% ~ 95% </li>
            <li>meetbereik eCO²: 400ppm ~ 32768ppm</li>
            <li>meetbereik eTVOC: 0ppb ~ 29206ppb</li>
            <li>leessnelheid = 100kHz (0.01ms)</li>
        </ul>
    </td>
    <td>Een minder bekende sensor maar zeker wel bekend in IoT toepassingen. Het kan temperatuur, eCO² en eTVOC. Het heeft geen opwarm tijd dus is direct bruikbaar. Het is ook een SMD component wat zeker een voordeel is om het zo compact mogelijk te maken.</td>
    <td><a target="_blank" href="https://www.tinytronics.nl/shop/nl/sensoren/ccs811-luchtkwaliteit-sensor">link</a></td>
</tr>
<tr>
    <td>GY-NEO6MV2</td>
    <td>
        <ul>
            <li><b>GPS module</b></li>
            <li>V<sub>cc</sub> = 3.3V-5V</li>
            <li>I<sub>max</sub> = 67mA</li>
            <li><a target="_blank" href="https://en.wikipedia.org/wiki/Universal_asynchronous_receiver-transmitter">UART</a> protocol 3.3V</li>
            <li>baudrate: 9600</li>
            <li>leessnelheid = 1Hz (1s)</li>
        </ul>
    </td>
    <td>De GPS module GY-NEO6MV2 is een zeer snel, klein en compacte module om de locatie te bepalen. Het is makkelijk implementeerbaar en makkelijk codeedbaar.</td>
    <td><a target="_blank" href="https://www.tinytronics.nl/shop/nl/communicatie/gps/gy-neo6mv2-gps-module">link</a></td>
</tr>
<tr>
    <td>SDS011</td>
    <td>
        <ul>
            <li><b>fijnstof sensor</b></li>
            <li>V<sub>cc</sub> = 5V</li>
            <li>I<sub>max</sub> = 200mA</li>
            <li><a target="_blank" href="https://en.wikipedia.org/wiki/Universal_asynchronous_receiver-transmitter">UART</a> protocol 3.3V</li>
            <li>baudrate: 9600</li>
            <li>Meetbereik PM2.5<sup>3</sup> & PM10<sup>4</sup>: 0μg/m3 ~ 999.9 μg/m3</li>
            <li>meetbereik luchtvochtigheid: 10% ~ 95% </li>
            <li>leessnelheid = 1Hz (1s)</li>
        </ul>
    </td>
    <td>de fijnstofsensor SDS011 is een veel gebruikte sensor voor DIY-projecten. Het zal niet de nauwkeurigste zijn maar zeker wel 1 van de goedkoopste. En het geeft toch al een sterke indicatie van wat het gehalte is van fijnstof in de lucht.</td>
    <td><a target="_blank" href="https://www.tinytronics.nl/shop/nl/sensoren/nova-sds011-hoge-precisie-laser-stofsensor">link</a></td>
</tr>
<tr>
    <td>LM35</td>
    <td>
        <ul>
            <li><b>temperatuursensor</b></li>
            <li>V<sub>cc</sub> = 4V - 30V</li>
            <li>I<sub>max</sub> = 60µA</li>
            <li>analoge uitgang 0 mV + 10.0 mV/°C</li>
            <li>Meetbereik temperatuur: -55°C ~ +150°C - 1°C afwijking</li>
            <li>leessnelheid = continue</li>
        </ul>
    </td>
    <td>De LM35 is een analoge temperatuur sensor die veel wordt gebruikt in de industrie. Het heeft een zeer groot bereik van meeting. Het is ook een zeer nauwkeurige sensor.</td>
    <td><a target="_blank" href="https://www.tinytronics.nl/shop/nl/sensoren/lm35-to-92-thermometer-temperatuur-sensor">link</a></td>
</tr>
<tr>
    <td>MHZ19</td>
    <td>
        <ul>
            <li><b>CO²</b></li>
            <li>V<sub>cc</sub> = 4.9V - 5.1V</li>
            <li>I<sub>max</sub> = 125mA</li>
            <li><a target="_blank" href="https://en.wikipedia.org/wiki/Universal_asynchronous_receiver-transmitter">UART</a> protocol 3.3V</li>
            <li>Meetbereik: 400ppm ~ 2000ppm</li>
            <li>opwarmtijd: ~1min</li>
            <li>leessnelheid = 1Hz (1s)</li>
        </ul>
    </td>
    <td>argument</td>
    <td><a target="_blank" href="https://www.tinytronics.nl/shop/nl/sensoren/winsen-mh-z19c-co2-sensor-met-kabel">link</a></td>
</tr>
<tr>
    <td>BME280</td>
    <td>
        <ul>
            <li><b>temperatuur, barometer & luchtvochtigheid</b></li>
            <li>V<sub>cc</sub> = 3.3V</li>
            <li>I<sub>max</sub> = 3.6µA</li>
            <li><a target="_blank" href="https://en.wikipedia.org/wiki/I%C2%B2C">I²C</a> protocol 3.3V</li>
            <li>Meetbereik temperatuur: -40°C ~ +85°C</li>
            <li>Meetbereik luchtvochtigheid: 0% ~ 100%</li>
            <li>Meetbereik luchtdruk: 300hPa ~ 1100hPa</li>
            <li>leessnelheid = 1Hz (1s)</li>
        </ul>
    </td>
    <td>argument</td>
    <td><a target="_blank" href="https://www.tinytronics.nl/shop/nl/sensoren/temperatuur-lucht-vochtigheid/bme280-digitale-barometer-druk-en-vochtigheid-sensor-module">link</a></td>
</tr>
</table>

<div style="font-size: 75%; line-height: 0; position: relative; vertical-align: baseline; top: -0.5em">
<p>ppm<sup>1</sup>: Parts per million (ppm) oftewel delen per miljoen is een maat voor concentratie. <a target="_blank" href="https://nl.wikipedia.org/wiki/Parts_per_million">wikipedia</a></p>
<p>eTVOC<sup>2</sup>: alle vluchtige organische stoffen (zoals Benzeen, Tolueen, Glycolen en Terpenen). <a target="_blank" href="https://www.ecolucht.nl/formaldehydemeter/tvoc.html#:~:text=Een%20TVOC%20meting%20analyseert%20niet,Tolueen%2C%20Glycolen%20en%20Terpenen).">ecolucht.nl</a> </p>
<p>PM2.5<sup>3</sup>: zwevende stof met diameter kleiner dan 2.5µm<a target="_blank" href="https://www.irceline.be/nl/documentatie/faq/wat-is-fijnstof">irceline.be</a></p>
<p>PM10<sup>4</sup>: zwevende stof met diameter kleiner dan 10µm<a target="_blank" href="https://www.irceline.be/nl/documentatie/faq/wat-is-fijnstof">irceline.be</a></p>
</div>

### voeding etc.

De voeding moet 5V en 3.3V kunnen leveren. Als we al de I<sub>max</sub> optellen van al de sensoren die we gaan gebruiken en dit getal * 1.20 (20%) doen. dan hebben we de werkstroom die de voltage regulator minimum moet aankunnen. We hebben enkele opties om 5V en 3.3V te bekomen.
<ul>
<li>
met zenerdiode
</li>
<li>
met IC (LM78xx, LM3480, LM1117, LM317, ...)
</li>
</ul>
Voor stabiliteitsredenen, gaan we gebruik maken van IC regulatoren. We kunnen hierbij kiezen uit <i>fixed</i> en <i>variable</i> regulatoren. Fixed zijn uit fabriek uit de juiste waardes, mits kleine afwijking. de variable regulatoren moeten we zelf afstellen. We kunnen dit dan naukeurig maken maar voor deze opstelling is dit niet van belang. We zien immers dat de voedingspanningen wel wat variaties kunnen verdragen. Om alles compact te houden, gaan we de voorkeur geven om SMD componenten te gebruiken. We moeten natuurlijk wel kijken of deze de gevraagde stroom kan leveren.

> berekeningen aangaande stroombepaling

I =I1+I2+I3+I4

### hardware schema & pcb design

<img src="./picture/schema_hardware.png">