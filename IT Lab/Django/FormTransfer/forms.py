from django import forms

class Transfer(forms.Form):
    CAR_CHOICES=(('1','Mercedes'),('2','Ferrari'),('3','Porsche'))
    car=forms.ChoiceField(widget=forms.Select,choices=CAR_CHOICES)
    model=forms.CharField()