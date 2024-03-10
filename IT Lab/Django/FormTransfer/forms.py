from django import forms

class FormTransfer(forms.Form):
    CAR_CHOICES=(('1','Mercedes'),('2','Ferrari'),('3','Porsche'))
    select=forms.ChoiceField(widget=forms.Select,choices=CAR_CHOICES)