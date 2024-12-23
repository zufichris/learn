import { CustomThemeConfig } from "tailwindcss/types/config";



const colors= {
    primary: '#1d4ed8', 
    secondary: '#64748b', 
    warning: '#f59e0b', 
    success: '#10b981', 
    danger: '#ef4444', 
    dark: '#111827',  
    light: '#f3f4f6', 
  }

const  Theme= {
extend:{
  colors
}
}as Partial<CustomThemeConfig & {
    extend: Partial<CustomThemeConfig>;
}>

export default Theme