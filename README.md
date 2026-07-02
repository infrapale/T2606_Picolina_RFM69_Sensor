# T2606_Picolina_RFM69_Sensor
Generic  Sensor node tarnsmitting using rfm69

Value filtering process:
- read 10 values
- calculate a average of all
- remove outliers (delta > +/-20% )
- calculate an average of the rest
- set a new value
